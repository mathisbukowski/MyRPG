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
    sfTexture *texture = sfTexture_createFromFile("assets/inventory.png",
        NULL);

    add_key_to_keymap(&(main->keymap), sfKeyI, &change_inventory_state);
    init_bank_item_sprite(inventory);
    sfRectangleShape_setTexture(inventory_sprite, texture, sfFalse);
    sfRectangleShape_setSize(inventory_sprite, (sfVector2f){600, 600});
    inventory->inventory_back = inventory_sprite;
    inventory->state = -1;
    return inventory;
}

void free_inventory(inventory_t *inventory)
{
    for (int i = 0; item_bank[i].id != 0; i ++) {
        sfSprite_destroy(item_bank[i].sprite);
        sfText_destroy(item_bank[i].texte);
    }
    sfFont_destroy(inventory->font);
    sfTexture_destroy(inventory->texture);
    sfRectangleShape_destroy(inventory->inventory_back);
    free(inventory);
}
