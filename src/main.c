/*
** EPITECH PROJECT, 2024
** RPG_H
** File description:
** main.c
*/

#include "../include/rpg.h"

int check_tty(char **env)
{
    for (char **current_env = env; *current_env != NULL; ++current_env) {
        if (my_strncmp(*current_env, "DISPLAY", my_strlen("DISPLAY")) == 0)
            return 0;
    }
    return 1;
}

static void help(void)
{
    printf("Help Panel of RPG");
}

int print_help(int ac, char **av)
{
    if (my_strcmp(av[1], "-h") == 0) {
        help();
        return 1;
    }
    return 0;
}

int main(int ac, char **av, char **env)
{
    if (check_tty(env) != 0)
        return 84;
    return 0;
}
