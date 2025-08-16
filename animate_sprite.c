/*
** EPITECH PROJECT, 2021
** B-MUL-100-RUN-1-1-myrunner-guillyann.ferrere
** File description:
** animate_sprite.c
*/

#include "include/struct.h"
#include "include/my.h"
#include "include/global.h"
#include <stdlib.h>
#include <stdio.h>

float time_as_ms(sfClock *clock)
{
    return (sfTime_asMilliseconds(sfClock_getElapsedTime(clock)));
}

animable_sprite_t create_walk_sprite(sfClock *clock)
{
    animable_sprite_t sprite = {0};

    sprite.sprite = sfSprite_create();
    sprite.tex = sfTexture_createFromFile("assets/walk.png", NULL);
    sfSprite_setTexture(sprite.sprite, sprite.tex, sfFalse);
    sfSprite_setPosition(sprite.sprite, (sfVector2f){0, 800});
    sprite.current_animation = 0;
    sprite.last_animation_time = time_as_ms(clock);
    sprite.animation_frame = 50;
    for (unsigned int i = 0; i < 16; i++) {
        sprite.rects[i] = WALK_RECTS[i];
    }
    sfSprite_setTextureRect(sprite.sprite,
        sprite.rects[sprite.current_animation]);
    sprite.rects_count = 16;
    return (sprite);
}

animable_sprite_t create_ennemy_sprite(sfClock *clock, int x)
{
    animable_sprite_t sprite = {0};

    sprite.sprite = sfSprite_create();
    sprite.tex = sfTexture_createFromFile("assets/ennemy.png", NULL);
    sfSprite_setTexture(sprite.sprite, sprite.tex, sfFalse);
    sfSprite_setPosition(sprite.sprite, (sfVector2f){x, 830});
    sprite.current_animation = 0;
    sprite.last_animation_time = time_as_ms(clock);
    sprite.animation_frame = 50;
    for (unsigned int i = 0; i < 16; i++) {
        sprite.rects[i] = ENNEMY_RECTS[i];
    }
    sfSprite_setTextureRect(sprite.sprite,
        sprite.rects[sprite.current_animation]);
    sprite.rects_count = 16;
    return (sprite);
}

animable_sprite_t create_jump_sprite(sfClock *clock)
{
    animable_sprite_t sprite = {0};

    sprite.sprite = sfSprite_create();
    sprite.tex = sfTexture_createFromFile("assets/jump.png", NULL);
    sfSprite_setTexture(sprite.sprite, sprite.tex, sfFalse);
    sfSprite_setPosition(sprite.sprite, (sfVector2f){0, 800});
    sprite.current_animation = 0;
    sprite.last_animation_time = time_as_ms(clock);
    sprite.animation_frame = 150;
    for (unsigned int i = 0; i < 9; i++) {
        sprite.rects[i] = JUMP_RECTS[i];
    }
    sfSprite_setTextureRect(sprite.sprite,
        sprite.rects[sprite.current_animation]);
    sprite.rects_count = 9;
    return (sprite);
}

void animate_sprite(animable_sprite_t *animable,
    sfClock *clock)
{
    const float current_time = time_as_ms(clock);

    if (current_time >=
        animable->last_animation_time + animable->animation_frame) {
        animable->last_animation_time = current_time;
        if (animable->current_animation == animable->rects_count) {
            animable->current_animation = 0;
        }
        sfSprite_setTextureRect(animable->sprite,
            animable->rects[animable->current_animation]);
        animable->current_animation++;
    }
}