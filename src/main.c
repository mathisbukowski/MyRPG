/*
** EPITECH PROJECT, 2024
** RPG_H
** File description:
** main.c
*/

#include "../include/rpg.h"

int main(int ac, char **av, char **env)
{
    if (check_tty(env) != 0)
        return 84;
    return 0;
}
