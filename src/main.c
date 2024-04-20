/*
** EPITECH PROJECT, 2024
** RPG_H
** File description:
** main.c
*/

#include "../include/rpg.h"

int main(int ac, char **av, char **env)
{
//    if (check_tty(env) != 0)
//        return 84;
//    if (print_help(ac, av) != 0)
//        return 0;
//    else if (ac < 1 || ac > 3)
//        return 84;
    if (game_loop(ac, av) != 0)
        return 84;
    return 0;
}
