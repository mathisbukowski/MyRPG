/*
** EPITECH PROJECT, 2024
** rpg_dev
** File description:
** init_inventory.c
*/
#include "rpg.h"

inventory_t *init_inventory(void)
{
    inventory_t *inventory = malloc(sizeof(inventory_t));

    init_bank_item_sprite();
    inventory->slot = malloc(sizeof(item_t *) * 5);
    for (int i = 0; i < 5; i ++) {
        inventory->slot[i] = malloc(sizeof(item_t) * 5);
        for (int j = 0; j < 5; j ++) {
            inventory->slot[i][j].sprite = NULL;
        }
    }
    inventory->inventory_back = sfSprite_create();
    return inventory;
}

void free_inventory(inventory_t *inventory)
{
    int x = 0;

    for (int i = 0; i < 5; i ++) {
        sfSprite_destroy(inventory->slot[i]->sprite);
        free(inventory->slot[i]);
    }
    while (item_bank[x].id != 0) {
        sfSprite_destroy(item_bank[x].sprite);
        x ++;
    }
    free(inventory->slot);
    sfSprite_destroy(inventory->inventory_back);
    free(inventory);
}
