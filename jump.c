/*
** EPITECH PROJECT, 2021
** B-MUL-100-RUN-1-1-myrunner-guillyann.ferrere
** File description:
** jump.c
*/

#include "include/my.h"
#include "include/struct.h"

void check_button(my_runner_t *init)
{
    if (sfKeyboard_isKeyPressed(sfKeySpace)) {
        init->current_animation = &init->animable_jump;
        sfSound_play(init->jump_sound);
        if (init->jump < 1) {
            init->jump++;
            init->speed.y = -20;
        }
    }
}

my_runner_t *jump(my_runner_t *init)
{
    sfVector2f pos_sprite =
        sfSprite_getPosition(init->current_animation->sprite);

    check_button(init);
    init->speed.y += 0.50;
    pos_sprite.y += init->speed.y;
    if (pos_sprite.y >= 800) {
        pos_sprite.y = 800;
        init->jump = 0;
        init->speed.y = 0;
    }
    if (init->jump == 0)
        init->current_animation = &init->animable_walk;
    sfSprite_setPosition(init->current_animation->sprite, pos_sprite);
    return (init);
}
