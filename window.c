/*
** EPITECH PROJECT, 2021
** B-MUL-100-RUN-1-1-myrunner-guillyann.ferrere
** File description:
** window.c
*/

#include "include/struct.h"
#include "include/my.h"
#include <stdlib.h>
#include <unistd.h>

my_runner_t *close_window(my_runner_t *init)
{
    if (init->w.event.type == sfEvtClosed ||
        (sfKeyboard_isKeyPressed(sfKeyEscape)))
        sfRenderWindow_close(init->w.window);
    return (init);
}
