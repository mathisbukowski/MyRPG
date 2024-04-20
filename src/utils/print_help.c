/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** print_help.c
*/

#include "../../include/rpg.h"

static void help(void)
{
    printf("Help Panel of RPG");
}

int print_help(int ac, char **av)
{
    if (strcmp(av[1], "-h") == 0) {
        help();
        return 1;
    }
    return 0;
}
