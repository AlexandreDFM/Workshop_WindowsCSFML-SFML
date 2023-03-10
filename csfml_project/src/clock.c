/*
** EPITECH PROJECT, 2023
** Workshop_WindowsCSFML-SFML
** File description:
** clock.c
*/

#include "../include/game.h"

void animation_clock(game_t *hunter)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(hunter->animation_clock)) > 0.05) {
        sfClock_restart(hunter->animation_clock);
        for (linked_list_t *node = hunter->ducks; node != NULL; node = node->next) {
            sfSprite *sprite = node->data;
            sfVector2f pos = sfSprite_getPosition(sprite);
            if (pos.x > 800) continue;
            if (sfSprite_getTextureRect(sprite).left == 70)
                sfSprite_setTextureRect(sprite, (sfIntRect){0, 0, 35, 42});
            else
                sfSprite_setTextureRect(sprite, (sfIntRect){sfSprite_getTextureRect(sprite).left + 35, 0, 35, 42});
            return;
        }
    }
}

void game_clock(game_t *hunter)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(hunter->clock)) > 0.05 / hunter->speed) {
        sfClock_restart(hunter->clock); animation_clock(hunter);
        for (linked_list_t *node = hunter->ducks; node != NULL; node = node->next) {
            sfSprite *sprite = node->data;
            sfVector2f pos = sfSprite_getPosition(sprite);
            if (pos.x > 800) continue;
            sfSprite_setPosition(sprite, (sfVector2f){pos.x + 10, pos.y});
            return;
        }
        for (linked_list_t *node = hunter->ducks; node != NULL; node = node->next) {
            sfSprite *sprite = node->data;
            sfSprite_setPosition(sprite, (sfVector2f){-300, rand() % 400});
            sfSprite_setTextureRect(sprite, (sfIntRect){0, 0, 35, 42});
        }
    }
}
