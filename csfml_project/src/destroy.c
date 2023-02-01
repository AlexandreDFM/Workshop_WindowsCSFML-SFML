/*
** EPITECH PROJECT, 2023
** Workshop_WindowsCSFML-SFML
** File description:
** destroy.c
*/

#include "../include/game.h"

void destroy(game_t *hunter)
{
    for (linked_list_t *node = hunter->ducks; node != NULL; node = node->next) {
        sfSprite *sprite = node->data;
        sfSprite_destroy(sprite);
    }
//    for (int i = 0; i < 2; i++) {
//        sfTexture_destroy(hunter->textures[i]);
//        sfSprite_destroy(hunter->backgrounds[i]);
//    }
//    sfTexture_destroy(hunter->textures[2]);
    sfSprite_destroy(hunter->cursor);
    sfRenderWindow_destroy(hunter->window);
    sfClock_destroy(hunter->clock);
    free(hunter->ducks);
}

sfTexture *create_texture(char *path, game_t *hunter, sfBool is_new)
{
    if (is_new == sfFalse) {
        for (linked_list_t *node = hunter->textures; node != NULL; node = node->next) {
            sfTexture *texture = node->data; sfTexture_destroy(texture);
        }
        return NULL;
    }
    sfTexture *texture = sfTexture_createFromFile(path, NULL);
    if (!texture) {
        write(2, "Error: texture not found", 24); exit(84);
    }
    linked_list_t *node = malloc(sizeof(linked_list_t));
    linked_list_t *tmp = hunter->textures;
    if (tmp == NULL) {
        node->data = texture; node->next = NULL; hunter->textures = node;
        return texture;
    }
    for (; tmp->next != NULL; tmp = tmp->next);
    node->data = texture; node->next = NULL; tmp->next = node;
    return texture;
}
