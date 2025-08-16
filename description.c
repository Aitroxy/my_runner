/*
** EPITECH PROJECT, 2021
** B-MUL-100-RUN-1-1-myrunner-guillyann.ferrere
** File description:
** descritpion.c
*/

#include "include/my.h"
#include <unistd.h>

int description(void)
{
    write(1, "Usage : ./my_runner map.txt to start the game\n", 47);
    write(1, "Press space to jump\n", 21);
    write(1, "If an ennemy hits your character the game will end\n", 52);
    write(1, "Your score will be show at the end of the game\n", 48);
    write(1, "Press escape to quit the game\n", 31);
    return (0);
}
