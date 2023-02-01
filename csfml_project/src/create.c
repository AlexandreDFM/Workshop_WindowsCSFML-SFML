/*
** EPITECH PROJECT, 2023
** Workshop_WindowsCSFML-SFML
** File description:
** create.c
*/

#include "../include/game.h"

sfSprite *create_sprite(sfTexture *texture, sfIntRect rect,
sfVector2f pos, sfVector2f scale)
{
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setTextureRect(sprite, rect);
    sfSprite_setPosition(sprite, pos);
    sfSprite_setScale(sprite, scale);
    return sprite;
}
