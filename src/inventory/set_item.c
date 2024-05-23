/*
** EPITECH PROJECT, 2024
** rpg_dev
** File description:
** set_item.c
*/
#include "rpg.h"

int find_id(char *item)
{
    for (int i = 0; item_bank[i].id != 0; i ++) {
        if (my_strcmp(item_bank[i].name, item))
            return i;
    }
    return -1;
}

void init_bank_item_sprite(void)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile("assets/item.png",
        NULL);

    if (check_texture(sprite, texture)) {
        sfSprite_destroy(sprite);
        return;
    }
    for (int i = 0; i < 10; i ++) {
        item_bank[i].sprite = sfSprite_create();
        sfSprite_setTexture(item_bank[i].sprite, texture, sfFalse);
        sfSprite_setTextureRect(item_bank[i].sprite, *item_bank[i].rect);
        sfSprite_setPosition(item_bank[i].sprite,
            (sfVector2f){710, (float)(250 + (i * 58))});
    }
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
}

item_t item_bank[] = {
    {1, 0, "houe", &(sfIntRect){144, 0, 48, 48}, NULL},
    {2, 0, "pioche", &(sfIntRect){192, 0, 48, 48}, NULL},
    {3, 0, "hache", &(sfIntRect){288, 0, 48, 48}, NULL},
    {4, 0, "épée", &(sfIntRect){240, 0, 48, 48}, NULL},
    {5, 0, "pierre", &(sfIntRect){96, 0, 48, 48}, NULL},
    {6, 0, "bois", &(sfIntRect){48, 0, 48, 48}, NULL},
    {7, 0, "poisson", &(sfIntRect){0, 0, 48, 48}, NULL},
    {8, 0, "carotte", &(sfIntRect){432, 0, 48, 48}, NULL},
    {9, 0, "tomate", &(sfIntRect){384, 0, 48, 48}, NULL},
    {10, 0, "pomme de terre", &(sfIntRect){336, 0, 48, 48}, NULL},
    {0, 0, NULL, NULL, NULL}
};
