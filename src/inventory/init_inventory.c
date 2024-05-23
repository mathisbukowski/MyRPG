/*
** EPITECH PROJECT, 2024
** rpg_dev
** File description:
** init_inventory.c
*/
#include "rpg.h"

inventory_t *init_inventory_sprite(rpg_t *main)
{
    inventory_t *inventory = malloc(sizeof(inventory_t));
    sfRectangleShape *inventory_sprite = sfRectangleShape_create();

    add_key_to_keymap(&(main->keymap), sfKeyI, &change_inventory_state);
    init_bank_item_sprite();
    sfRectangleShape_setSize(inventory_sprite, (sfVector2f){550, 600});
    sfRectangleShape_setPosition(inventory_sprite, (sfVector2f){685, 240});
    sfRectangleShape_setFillColor(inventory_sprite,
        (sfColor){169, 169, 169, 255});
    inventory->inventory_back = inventory_sprite;
    inventory->state = -1;
    return inventory;
}

void free_inventory(inventory_t *inventory)
{
    for (int i = 0; item_bank[i].id != 0; i ++) {
        sfSprite_destroy(item_bank[i].sprite);
    }
    sfRectangleShape_destroy(inventory->inventory_back);
    free(inventory);
}
