/*
** EPITECH PROJECT, 2021
** B-MUL-100-RUN-1-1-myrunner-guillyann.ferrere
** File description:
** ennemy_clash.c
*/

#include "include/my.h"
#include "include/struct.h"
#include <stdio.h>

int ennemy_clash(my_runner_t *init)
{
    sfFloatRect player =
        sfSprite_getGlobalBounds(init->current_animation->sprite);

    for (int i = 0; init->nb_ennemy > i; i++) {
        sfFloatRect ennemy =
            sfSprite_getGlobalBounds(init->animable_ennemy[i].sprite);
        if (sfFloatRect_intersects(&player, &ennemy, NULL))
            return (1);
    }
    return (0);
}