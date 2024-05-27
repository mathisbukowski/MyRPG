/*
** EPITECH PROJECT, 2024
** RPG_H
** File description:
** main.c
*/

#include "rpg.h"

int main(const int ac, char **av, char **env)
{
    UNUSED(ac);
    if (check_tty(env) != 0)
        return 84;
    if (game_logic(av) != 0)
        return 84;
    return 0;
}
