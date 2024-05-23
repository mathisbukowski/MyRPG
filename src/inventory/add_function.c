/*
** EPITECH PROJECT, 2024
** rpg_dev
** File description:
** add_function.c
*/
#include "rpg.h"

int add_inventory(rpg_t *main, char *name, int nb)
{
    int x = find_id(name);

    if (x < 0)
        return 1;
    item_bank[x].quantity += nb;
    return 0;
}
