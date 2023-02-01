/*
** EPITECH PROJECT, 2023
** Workshop_WindowsCSFML-SFML
** File description:
** click.c
*/

#include "../include/game.h"

char *my_itoa(int nb)
{
    int i = 0, j = 0;
    char *str = malloc(sizeof(char) * 10);
    int nb2 = nb;
    for (; nb2 > 0; i++) nb2 = nb2 / 10;
    str[i] = '\0';
    for (; nb > 0; j++) {
        str[i - j - 1] = nb % 10 + 48; nb = nb / 10;
    }
    return str;
}

void click(game_t *hunter)
{
    if (hunter->event.type == sfEvtMouseButtonPressed) {
        sfSound_play(hunter->shoot_sound);
        sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(hunter->window);
        for (linked_list_t *node = hunter->ducks; node != NULL; node = node->next) {
            sfSprite *sprite = node->data;
//            sfVector2f pos = sfSprite_getPosition(sprite);
            sfFloatRect rect = sfSprite_getGlobalBounds(sprite);
            if (sfFloatRect_contains(&rect, mouse_pos.x, mouse_pos.y)) {
                sfSprite_setPosition(sprite, (sfVector2f){-68, 800});
                sfSprite_setTextureRect(sprite, (sfIntRect){0, 0, 35, 42});
                hunter->score_nb += 100;
                sfText_setString(hunter->score, my_itoa(hunter->score_nb));
                sfSound_play(hunter->hit_sound);
            }
        }
    }
}
