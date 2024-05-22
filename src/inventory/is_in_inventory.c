/*
** EPITECH PROJECT, 2024
** rpg_dev
** File description:
** is_in_inventory.c
*/
#include "rpg.h"

static int is_in_inventory_loop(rpg_t*main, int i, char *item)
{
    for (int j = 0; j < 5; j++) {
        if (my_strcmp(main->inventory->slot[i][j].name, item) == 0)
            return 0;
    }
    return 1;
}

int is_in_inventory(rpg_t *main, char *item)
{
    for (int i = 0; i < 5; i ++) {
        if (is_in_inventory_loop(main, i, item) == 0) {
            return 0;
        }
    }
    return 1;
}
