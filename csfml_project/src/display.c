/*
** EPITECH PROJECT, 2023
** Workshop_WindowsCSFML-SFML
** File description:
** display.c
*/

#include "../include/game.h"

void display_ducks(game_t *hunter)
{
    for (linked_list_t *node = hunter->ducks; node != NULL; node = node->next) {
        sfSprite *sprite = node->data;
        sfRenderWindow_drawSprite(hunter->window, sprite, NULL);
    }
}
