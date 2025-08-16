/*
** EPITECH PROJECT, 2021
** B-MUL-100-RUN-1-1-myrunner-guillyann.ferrere
** File description:
** struct.h
*/

#ifndef _STRUCT_H
    #define _STRUCT_H
    #define MAX_ANIMATIONS (50)

    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>

typedef enum textures_s {
    MOON,
    FOREST_1,
    FOREST_2,
    FOREST_3,
    GROUND,
    TREES
} textures_t;

typedef struct config_layer_s {
    textures_t name;
    float speed;
} config_layer_t;

typedef struct parallax_layer_s {
    textures_t name;
    sfSprite *sprite;
    float speed;
} parallax_layer_t;

typedef struct parallax_s {
    parallax_layer_t *layers;
    int size;
} parallax_t;

typedef struct window_s {
    sfRenderWindow *window;
    sfVideoMode video_mod;
    sfEvent event;
}window_t;

typedef struct animable_sprite_s {
    sfSprite *sprite;
    sfTexture *tex;
    sfIntRect rects[MAX_ANIMATIONS];
    unsigned int rects_count;
    unsigned int current_animation;
    float last_animation_time;
    float animation_frame;
} animable_sprite_t;

typedef enum menu_s {
    GAME,
    GAME_OVER
} menu_t;

typedef struct my_runner_s {
    window_t w;
    sfClock *clock;
    menu_t menu;
    animable_sprite_t *current_animation;
    animable_sprite_t animable_walk;
    animable_sprite_t animable_jump;
    animable_sprite_t *animable_ennemy;
    parallax_t *parallax;
    sfTexture **textures;
    int jump;
    sfVector2f speed;
    int choose_ennemy;
    int nb_ennemy;
    sfMusic *main_music;
    sfSound *jump_sound;
    sfSoundBuffer *buffer_sound;
    sfText *text;
    sfFont *type_write;
    long score;
    char buffer_score[8];
    sfSprite *game_over;
    sfTexture *tex_game_over;
}my_runner_t;

#endif