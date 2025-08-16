/*
** EPITECH PROJECT, 2021
** B-MUL-100-RUN-1-1-myrunner-guillyann.ferrere
** File description:
** init.c
*/

#include "include/struct.h"
#include <stdlib.h>
#include "include/my.h"
#include <stdlib.h>

my_runner_t *init_sound(my_runner_t *init)
{
    init->main_music = sfMusic_createFromFile("./assets/JoJo.ogg");
    init->jump_sound = sfSound_create();
    init->buffer_sound = sfSoundBuffer_createFromFile("./assets/jump.wav");
    sfSound_setBuffer(init->jump_sound, init->buffer_sound);
    return (init);
}

my_runner_t *init_parallax_sprite(my_runner_t *init)
{
    char *paths[] = {"layers/2.png", "layers/3.png", "layers/4.png",
        "layers/5.png", "layers/7.png", "layers/8.png", NULL};
    config_layer_t configs[] = {{MOON, 0}, {FOREST_1, 1}, {FOREST_2, 2},
        {FOREST_3, 3}, {GROUND, 4}, {TREES, 4}};

    init->textures = load_para(paths);
    init->clock = sfClock_create();
    init->animable_walk = create_walk_sprite(init->clock);
    init->animable_jump = create_jump_sprite(init->clock);
    init->current_animation = &init->animable_walk;
    init->parallax = create_para(6, configs, init->textures);
    return (init);
}

my_runner_t *init_score(my_runner_t *init)
{
    init->type_write = sfFont_createFromFile("./assets/text.ttf");
    init->text = sfText_create();
    sfText_setScale(init->text, (sfVector2f){2, 2});
    sfText_setFont(init->text, init->type_write);
    sfText_setColor(init->text, sfWhite);
    sfText_setPosition(init->text, (sfVector2f){950, 30});
    return (init);
}

my_runner_t *init_game_over(my_runner_t *init)
{
    init->game_over = sfSprite_create();
    init->tex_game_over =
        sfTexture_createFromFile("assets/game_over.png", NULL);
    sfSprite_setTexture(init->game_over, init->tex_game_over, sfFalse);
    return (init);
}

my_runner_t *init_types(my_runner_t *init)
{
    init->w.video_mod = (sfVideoMode){1920, 1080, 60};
    init->jump = 0;
    init->speed.y = 0;
    init->menu = GAME;
    init_sound(init);
    init->score = 0;
    init->w.window = sfRenderWindow_create(init->w.video_mod,
        "my_runner", sfClose | sfResize, NULL);
    sfRenderWindow_setFramerateLimit(init->w.window, 60);
    init_parallax_sprite(init);
    init_score(init);
    init_game_over(init);
    sfMusic_play(init->main_music);
    sfMusic_setLoop(init->main_music, sfTrue);
    return (init);
}
