/*
** EPITECH PROJECT, 2021
** B-MUL-100-RUN-1-1-myrunner-guillyann.ferrere
** File description:
** destroy_free.c
*/

#include "include/my.h"
#include "include/struct.h"
#include <stdlib.h>

void destroy_textures(sfTexture **textures)
{
    int i = 0;

    if (!textures)
        return;
    while (textures[i]) {
        sfTexture_destroy(textures[i]);
        i++;
    }
    free(textures);
}

void destroy_all(my_runner_t *init, char *map)
{
    destroy_para(init->parallax);
    destroy_textures(init->textures);
    sfSprite_destroy(init->animable_walk.sprite);
    sfTexture_destroy(init->animable_walk.tex);
    sfSprite_destroy(init->animable_jump.sprite);
    sfTexture_destroy(init->animable_jump.tex);
    sfSprite_destroy(init->game_over);
    sfTexture_destroy(init->tex_game_over);
    for (int i = 0; i < init->nb_ennemy; i++) {
        sfSprite_destroy(init->animable_ennemy[i].sprite);
        sfTexture_destroy(init->animable_ennemy[i].tex);
    }
    sfMusic_stop(init->main_music);
    sfMusic_destroy(init->main_music);
    sfSound_destroy(init->jump_sound);
    sfSoundBuffer_destroy(init->buffer_sound);
    free(map);
    free(init->animable_ennemy);
    free(init);
}
