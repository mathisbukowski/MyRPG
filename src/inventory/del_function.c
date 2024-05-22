/*
** EPITECH PROJECT, 2024
** rpg_dev
** File description:
** manage_inventory.c
*/
#include "rpg.h"

void delete_inventory(rpg_t *main, int x, int y)
{
    main->inventory->slot[y][x] = item_bank[10];
}
