/*
** EPITECH PROJECT, 2023
** Workshop_WindowsCSFML-SFML
** File description:
** myhunter.c
*/

#include "../include/game.h"

int game(game_t *hunter)
{
    for (; sfRenderWindow_isOpen(hunter->window);) {
        for (;sfRenderWindow_pollEvent(hunter->window, &hunter->event);) {
            if (hunter->event.type == sfEvtClosed)
                sfRenderWindow_close(hunter->window);
        }
        sfRenderWindow_clear(hunter->window, sfBlack);
        game_clock(hunter);
        sfRenderWindow_drawSprite(hunter->window, hunter->backgrounds[BACKGROUND], NULL);
        sfRenderWindow_drawSprite(hunter->window, hunter->backgrounds[FOREGROUND], NULL);
        sfRenderWindow_drawSprite(hunter->window, hunter->backgrounds[BACK_LIFE], NULL);
        sfRenderWindow_drawSprite(hunter->window, hunter->backgrounds[LIFE], NULL);
        cursor(hunter);
        display_ducks(hunter);
        click(hunter);
        sfRenderWindow_drawText(hunter->window, hunter->score, NULL);
        sfRenderWindow_drawSprite(hunter->window, hunter->cursor, NULL);
        sfRenderWindow_display(hunter->window);
    }
    return 0;
}
