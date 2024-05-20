/*
** EPITECH PROJECT, 2024
** RPG_H
** File description:
** main.c
*/

#include "rpg.h"

int main(int ac, char **av, char **env)
{
    if (check_tty(env) != 0)
        return 84;
    load_map("assets/map/test_map.tmx");
    my_putstr("Map loaded\n");
    if (game_loop(ac, av) != 0)
        return 84;
    return 0;
}
