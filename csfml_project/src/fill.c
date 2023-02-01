/*
** EPITECH PROJECT, 2023
** Workshop_WindowsCSFML-SFML
** File description:
** fill.c
*/

#include "../include/game.h"

linked_list_t *fill_ducks(game_t *hunter)
{
    sfTexture *texture = create_texture("./assets/img/ducks/ducks.png", hunter, sfTrue);
    hunter->ducks = NULL;
    for (int i = 0; i < 10; i++) {
        sfSprite *sprite = create_sprite(texture, (sfIntRect){0, 0, 35, 42},
        (sfVector2f){-300, rand() % 400}, (sfVector2f){RESIZE_X, RESIZE_Y});
        linked_list_t *node = malloc(sizeof(linked_list_t));
        node->data = sprite;
        node->next = hunter->ducks;
        hunter->ducks = node;
    }
    return hunter->ducks;
}

void fill_backgrounds(game_t *hunter)
{
    sfTexture *texture = create_texture("./assets/img/background.png", hunter, sfTrue);
    hunter->backgrounds[0] = create_sprite(texture, (sfIntRect){0, 0, 800, 600},
    (sfVector2f){0, 0}, (sfVector2f){RESIZE_X, RESIZE_Y});
    sfTexture *texture2 = create_texture("./assets/img/foreground.png", hunter, sfTrue);
    hunter->backgrounds[1] = create_sprite(texture2, (sfIntRect){0, 0, 800, 600},
    (sfVector2f){0, 0}, (sfVector2f){RESIZE_X, RESIZE_Y});
}

void fill_struct(game_t *hunter)
{
    hunter->window = sfRenderWindow_create((sfVideoMode){800, 600, 32}, "My Hunter", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(hunter->window, 60);
    hunter->event = (sfEvent){0};
    hunter->textures = NULL;
    sfTexture *cursor_texture = create_texture("./assets/img/interface/cursor.png", hunter, sfTrue);
    hunter->cursor = create_sprite(cursor_texture, (sfIntRect){0, 0, 25, 23},
    (sfVector2f){0, 0}, (sfVector2f){1, 1});
    sfSprite_setOrigin(hunter->cursor, (sfVector2f){12.5, 11.5});
    sfRenderWindow_setMouseCursorVisible(hunter->window, sfFalse);

    hunter->score_nb = 0;
    hunter->score = sfText_create();
    sfText_setString(hunter->score, "0");
    sfText_setFont(hunter->score, sfFont_createFromFile("./assets/fonts/font_8bit.ttf"));
    sfText_setCharacterSize(hunter->score, 50);
    sfText_setPosition(hunter->score, (sfVector2f){10, 10});
    sfText_setColor(hunter->score, sfBlack);

    hunter->shoot_sound = sfSound_create();
    sfSound_setBuffer(hunter->shoot_sound, sfSoundBuffer_createFromFile("./assets/sounds/shoot_sound.ogg"));
    hunter->hit_sound = sfSound_create();
    sfSound_setBuffer(hunter->hit_sound, sfSoundBuffer_createFromFile("./assets/sounds/hit_sound.ogg"));

    fill_backgrounds(hunter);
    hunter->ducks = fill_ducks(hunter);
    hunter->clock = sfClock_create();
}
