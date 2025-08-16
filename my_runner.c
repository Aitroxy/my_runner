/*
** EPITECH PROJECT, 2021
** B-MUL-100-RUN-1-1-myrunner-guillyann.ferrere
** File description:
** my_runner.c
*/

#include "include/struct.h"
#include <stdlib.h>
#include "include/my.h"
#include <stdio.h>

int check_error(int ac, char **av, char *map)
{
    if (ac < 2 || ((av[1][0] == '-') && (av[1][1] == 'h')) || ac > 2) {
        description();
        free(map);
        return (-1);
    }
    map = manage_map(map, av);
    if (map == NULL) {
        description();
        free(map);
        return (-1);
    }
    return (0);
}

void ennemy_loop(my_runner_t *init)
{
    for (int i = 0; i < init->nb_ennemy; i++) {
        sfSprite_move(init->animable_ennemy[i].sprite, (sfVector2f){-5 , 0});
        animate_sprite(&init->animable_ennemy[i], init->clock);
        sfRenderWindow_drawSprite(init->w.window,
            init->animable_ennemy[i].sprite, NULL);
    }
}

void game_over_loop(my_runner_t *init)
{
    if (ennemy_clash(init) == 1)
        init->menu = GAME_OVER;
}

void game_loop(my_runner_t *init)
{
    if (init->menu == GAME) {
        init = jump(init);
        para_move(init->parallax);
        display_para(init->parallax, init->w.window);
        animate_sprite(init->current_animation, init->clock);
        sfRenderWindow_drawSprite(init->w.window,
            init->current_animation->sprite, NULL);
        ennemy_loop(init);
        game_over_loop(init);
        init->score++;
        int_to_str(init->score, init->buffer_score);
        sfText_setString(init->text, init->buffer_score);
        sfRenderWindow_drawText(init->w.window, init->text, NULL);
    } else if (init->menu == GAME_OVER) {
        sfRenderWindow_drawSprite(init->w.window, init->game_over, NULL);
        sfMusic_stop(init->main_music);
        sfRenderWindow_drawText(init->w.window, init->text, NULL);
    }
}

int main(int ac, char **av)
{
    my_runner_t *init = NULL;
    char *map = malloc(sizeof(map) * 800);

    map = correct_malloc(map, 800);
    if (check_error(ac, av, map) == -1)
        return (84);
    init = malloc(sizeof(my_runner_t));
    init = init_types(init);
    init = set_ennemy(init, map);
    while (sfRenderWindow_isOpen(init->w.window)) {
        sfRenderWindow_clear(init->w.window, sfBlack);
        while (sfRenderWindow_pollEvent(init->w.window, &init->w.event))
            init = close_window(init);
        game_loop(init);
        sfRenderWindow_display(init->w.window);
    }
    destroy_all(init, map);
    return (0);
}