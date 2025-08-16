/*
** EPITECH PROJECT, 2021
** B-MUL-100-RUN-1-1-myrunner-guillyann.ferrere
** File description:
** array_len.c
*/

#include "include/my.h"
#include "include/struct.h"

int array_len(char **array)
{
    int i = 0;

    while (array[i])
        i = i + 1;
    return i;
}
