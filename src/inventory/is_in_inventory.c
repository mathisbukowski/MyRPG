/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** is_in_inventory.c
*/

#include "rpg.h"

int is_in_inventory(rpg_t *main, char *item, int nb)
{
    for (int i = 0; item_bank[i].id != 0; i ++) {
        if (my_strcmp(item_bank[i].name, item) == 0 &&
            item_bank[i].quantity >= nb)
            return 1;
    }
    return 0;
}
