/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** check_tty.c
*/

#include "rpg.h"

int check_tty(char **env)
{
    for (char **current_env = env; *current_env != NULL; ++current_env) {
        if (strncmp(*current_env, "DISPLAY", strlen("DISPLAY")) == 0)
            return 0;
    }
    return 1;
}
