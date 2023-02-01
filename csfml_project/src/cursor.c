/*
** EPITECH PROJECT, 2023
** Workshop_WindowsCSFML-SFML
** File description:
** cursor.c
*/

#include "../include/game.h"

void cursor(game_t *hunter)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(hunter->window);
    sfVector2f pos = {mouse_pos.x, mouse_pos.y};
    sfSprite_setPosition(hunter->cursor, pos);
}
