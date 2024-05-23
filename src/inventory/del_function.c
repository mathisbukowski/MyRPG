/*
** EPITECH PROJECT, 2024
** rpg_dev
** File description:
** manage_inventory.c
*/
#include "rpg.h"

int delete_inventory(rpg_t *main, char *name, int nb)
{
    int x = find_id(name);

    if (x < 0)
        return 1;
    if (item_bank[x].quantity > nb) {
        item_bank[x].quantity -= nb;
        return 0;
    }
    return 1;
}
