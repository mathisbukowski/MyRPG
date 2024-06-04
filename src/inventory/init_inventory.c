/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** init_inventory.c
*/

#include "rpg.h"

void init_inventory_sprite(rpg_t *main)
{
    sfRectangleShape *inventory_sprite = sfRectangleShape_create();
    sfTexture *texture = sfTexture_createFromFile("assets/UI/inventory.png",
    NULL);

    main->inventory = malloc(sizeof(inventory_t));
    memset(main->inventory, 0, sizeof(inventory_t));
    add_key_to_keymap(&(main->keymap), sfKeyI, &change_inventory_state);
    init_bank_item_sprite(main->inventory);
    sfRectangleShape_setTexture(inventory_sprite, texture, sfFalse);
    sfRectangleShape_setSize(inventory_sprite, (sfVector2f){600, 600});
    main->inventory->inventory_back = inventory_sprite;
    main->inventory->state = -1;
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
