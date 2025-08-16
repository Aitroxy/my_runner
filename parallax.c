/*
** EPITECH PROJECT, 2021
** B-MUL-100-RUN-1-1-myrunner-guillyann.ferrere
** File description:
** parallax.c
*/

#include "include/my.h"
#include <stdlib.h>
#include "include/struct.h"

sfTexture **load_para(char **paths)
{
    sfTexture **textures = malloc(sizeof(sfTexture *) *
        (array_len(paths) + 1));
    int i = 0;

    while (paths[i]) {
        textures[i] = sfTexture_createFromFile(paths[i], NULL);
        i = i + 1;
    }
    textures[i] = NULL;
    return (textures);
}

parallax_t *create_para(int size, config_layer_t *conf, sfTexture **tex)
{
    parallax_t *para = malloc(sizeof(parallax_t));
    int i = 0;

    para->layers = malloc(sizeof(parallax_layer_t) * size);
    para->size = size;
    while (i < size) {
        para->layers[i].name = conf[i].name;
        para->layers[i].speed = conf[i].speed;
        para->layers[i].sprite = sfSprite_create();
        sfTexture_setRepeated(tex[conf[i].name], sfTrue);
        sfSprite_setTexture(para->layers[i].sprite,
            tex[conf[i].name], sfFalse);
        sfVector2u size = sfTexture_getSize(tex[conf[i].name]);
        sfIntRect rect = {0, 0, size.x, size.y};
        sfSprite_setTextureRect(para->layers[i].sprite, rect);
        i += 1;
    }
    return para;
}

void para_move(parallax_t *parallax)
{
    int i = 0;

    while (i < parallax->size) {
        sfIntRect rect = sfSprite_getTextureRect(parallax->layers[i].sprite);
        rect.left += parallax->layers[i].speed;
        sfSprite_setTextureRect(parallax->layers[i].sprite, rect);
        i += 1;
    }
}

void display_para(parallax_t *parallax, sfRenderWindow *win)
{
    int i = 0;

    while (i < parallax->size) {
        sfRenderWindow_drawSprite(win, parallax->layers[i].sprite, NULL);
        i += 1;
    }
}

void destroy_para(parallax_t *parallax)
{
    if (!parallax)
        return;
    for (int i = 0; i < parallax->size; i++) {
        sfSprite_destroy(parallax->layers[i].sprite);
    }
    free(parallax);
}
