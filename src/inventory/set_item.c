/*
** EPITECH PROJECT, 2024
** rpg_dev
** File description:
** set_item.c
*/
#include "rpg.h"

void init_bank_item_sprite(void)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile("../../assets/items",
        NULL);

    if (check_texture(sprite, texture)) {
        return;
    }
    sfSprite_setTexture(sprite, texture, sfFalse);
    for (int i = 0; i < 10; i ++) {
        sfSprite_setTextureRect(item_bank[i].sprite, *item_bank[i].rect);
    }
}

item_t item_bank[] = {
    {1, "pelle", &(sfIntRect){0, 0, 16, 16}, NULL},
    {2, "pioche", &(sfIntRect){0, 0, 16, 16}, NULL},
    {3, "hache", &(sfIntRect){0, 0, 16, 16}, NULL},
    {4, "épée", &(sfIntRect){0, 0, 16, 16}, NULL},
    {5, "pierre", &(sfIntRect){0, 0, 16, 16}, NULL},
    {6, "bois", &(sfIntRect){0, 0, 16, 16}, NULL},
    {7, "poisson", &(sfIntRect){0, 0, 16, 16}, NULL},
    {8, "carotte", &(sfIntRect){0, 0, 16, 16}, NULL},
    {9, "tomate", &(sfIntRect){0, 0, 16, 16}, NULL},
    {10, "salade", &(sfIntRect){0, 0, 16, 16}, NULL},
    {0, NULL, NULL, NULL}
};
