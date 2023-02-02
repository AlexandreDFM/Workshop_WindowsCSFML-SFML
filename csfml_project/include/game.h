/*
** EPITECH PROJECT, 2023
** Workshop_WindowsCSFML-SFML
** File description:
** hunter.h
*/
#ifndef HUNTER_H_
	#define HUNTER_H_

    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>
    #include <stdlib.h>
    #include <time.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <string.h>
    #include <stddef.h>

#define WIDTH 800
#define HEIGHT 600
#define FPS 60
#define SPEED 0.1
#define RESIZE_X 3.136
#define RESIZE_Y 2.5

enum interface_t {
    BACKGROUND,
    FOREGROUND,
    LIFE,
    BACK_LIFE,
    MAX_INTERFACE
};

typedef struct linked_list {
    void *data;
    struct linked_list *next;
} linked_list_t;

typedef struct game {
    int speed;
    int score_nb;
    sfText *score;
    sfEvent event;
    sfClock *clock;
    sfSprite *cursor;
    sfSound *hit_sound;
    sfSound *shoot_sound;
    linked_list_t *ducks;
    sfRenderWindow *window;
    linked_list_t *textures;
    sfSprite *backgrounds[MAX_INTERFACE];
    sfClock *animation_clock;
} game_t;

int game(game_t *hunter);
void click(game_t *hunter);
void cursor(game_t *hunter);
void destroy(game_t *hunter);
void game_clock(game_t *hunter);
void fill_struct(game_t *hunter);
void display_ducks(game_t *hunter);
sfSprite *create_sprite(sfTexture *texture, sfIntRect rect,
sfVector2f pos, sfVector2f scale);
sfTexture *create_texture(char *path, game_t *hunter, sfBool is_new);

#endif /*HUNTER_H_*/
