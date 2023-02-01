/*
** EPITECH PROJECT, 2023
** Workshop_WindowsCSFML-SFML
** File description:
** main.c
*/

#include "./include/game.h"

void print_manual()
{
    FILE *file = fopen("./assets/help.txt", "r");
    char *line = NULL; size_t len = 0;
    for (;(getline(&line, &len, file)) != -1;) {
        printf("%s", line);
    }
    fclose(file);
}

int main(int argc, char **argv) {
    game_t hunter;
    if (argc == 2 && strcmp(argv[1], "-h") == 0) {
        (void)hunter;
        print_manual();
    } else if (argc == 1) {
        fill_struct(&hunter);
        srand(time(0));
        game(&hunter);
    }
    destroy(&hunter);
    create_texture(NULL, &hunter, sfFalse);
    return 0;
}
