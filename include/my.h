/*
** EPITECH PROJECT, 2021
** B-MUL-100-RUN-1-1-myrunner-guillyann.ferrere
** File description:
** my.h
*/

#ifndef MY_H_
    #define MY_H_

    #include "struct.h"

my_runner_t *close_window(my_runner_t *init);
my_runner_t *init_types(my_runner_t *init);
int description(void);
my_runner_t *create_object(const char *path, sfVector2f pos, sfIntRect rect,
my_runner_t *init);
int array_len(char **array);
sfTexture **load_para(char **paths);
parallax_t *create_para(int size, config_layer_t *configs, sfTexture **text);
animable_sprite_t create_walk_sprite(sfClock *clock);
void animate_sprite(animable_sprite_t *animable, sfClock *clock);
void display_para(parallax_t *parallax, sfRenderWindow *win);
void destroy_para(parallax_t *parallax);
void para_move(parallax_t *parallax);
animable_sprite_t create_jump_sprite(sfClock *clock);
my_runner_t *jump(my_runner_t *init);
animable_sprite_t create_ennemy_sprite(sfClock *clock, int x);
int get_ennemy(char *buff);
char *manage_map(char *map, char **av);
my_runner_t *set_ennemy(my_runner_t *init, char *map);
char *correct_malloc(char *str, int size);
void destroy_all(my_runner_t *init, char *map);
void destroy_textures(sfTexture **textures);
int ennemy_clash(my_runner_t *init);
char *int_to_str(int nb, char *score);

#endif