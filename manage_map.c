/*
** EPITECH PROJECT, 2021
** B-MUL-100-RUN-1-1-myrunner-guillyann.ferrere
** File description:
** read_map.c
*/

#include "include/my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char *correct_malloc(char *str, int size)
{
    for (int i = 0; i < size; i++)
        str[i] = '\0';
    return (str);
}

int get_ennemy(char *buff)
{
    int compt = 0;
    int i = 0;

    while (buff[i] != '\0') {
        if (buff[i] == '1')
            compt++;
        i++;
    }
    return (compt);
}

my_runner_t *set_ennemy(my_runner_t *init, char *map)
{
    int i = 0;
    int x = 0;

    init->nb_ennemy = get_ennemy(map);
    init->animable_ennemy = malloc(sizeof(animable_sprite_t) *
        init->nb_ennemy);
    while (map[i] != '\0') {
        if (map[i] == '1') {
            init->animable_ennemy[init->choose_ennemy] =
                create_ennemy_sprite(init->clock, x);
            init->choose_ennemy++;
        }
        x += 80;
        i++;
    }
    return (init);
}

char *manage_map(char *map, char **av)
{
    int fd = open(av[1], O_RDONLY);

    if (fd == -1)
        return (NULL);
    read(fd, map, 800);
    map[799] = '\0';
    close(fd);
    return (map);
}
