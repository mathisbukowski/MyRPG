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

sfText *init_texte_item(sfFont *font, int i)
{
    sfText *texte = sfText_create();

    sfText_setString(texte, get_value_item(i));
    sfText_setFont(texte, font);
    sfText_setCharacterSize(texte, 30);
    sfText_setColor(texte, sfColor_fromRGB(255, 255, 255));
    sfText_setPosition(texte, (sfVector2f){260, (float)(250 + (i * 58))});
    return texte;
}

sfSprite *init_sprite_item(sfTexture *texture, int i)
{
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfFalse);
    sfSprite_setTextureRect(sprite, *item_bank[i].rect);
    sfSprite_setPosition(sprite, (sfVector2f){200, (float)(250 + (i * 58))});
    return sprite;
}

void init_bank_item_sprite(inventory_t *inventory)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile("assets/item.png",
        NULL);
    sfFont* font = sfFont_createFromFile("assets/font/arial.ttf");

    if (!font) {
        fprintf(stderr, "Error: file not found.\n");
        return;
    }
    if (check_texture(sprite, texture)) {
        sfSprite_destroy(sprite);
        return;
    }
    for (int i = 0; i < 10; i ++) {
        item_bank[i].texte = init_texte_item(font, i);
        item_bank[i].sprite = init_sprite_item(texture, i);
    }
    inventory->texture = texture;
    inventory->font = font;
    sfSprite_destroy(sprite);
}

item_t item_bank[] = {
    {1, 0, "houe", &(sfIntRect){144, 0, 48, 48}, NULL, NULL},
    {2, 0, "pioche", &(sfIntRect){192, 0, 48, 48}, NULL, NULL},
    {3, 0, "hache", &(sfIntRect){288, 0, 48, 48}, NULL, NULL},
    {4, 0, "épée", &(sfIntRect){240, 0, 48, 48}, NULL, NULL},
    {5, 0, "pierre", &(sfIntRect){96, 0, 48, 48}, NULL, NULL},
    {6, 0, "bois", &(sfIntRect){48, 0, 48, 48}, NULL, NULL},
    {7, 0, "poisson", &(sfIntRect){0, 0, 48, 48}, NULL, NULL},
    {8, 0, "carotte", &(sfIntRect){432, 0, 48, 48}, NULL, NULL},
    {9, 0, "tomate", &(sfIntRect){384, 0, 48, 48}, NULL, NULL},
    {10, 0, "pomme de terre", &(sfIntRect){336, 0, 48, 48}, NULL, NULL},
    {0, 0, NULL, NULL, NULL, NULL}
};
