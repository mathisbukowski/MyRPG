/*
** EPITECH PROJECT, 2024
** rpg_dev
** File description:
** display_inventory.c
*/
#include "rpg.h"

char *get_value_item(int x)
{
    char *buffer = malloc(sizeof(char) * 9);

    sprintf(buffer, ": %d", item_bank[x].quantity);
    return buffer;
}

void change_inventory_state(rpg_t *main)
{
    add_inventory(main, "pioche", 100);
    main->inventory->state *= -1;
}

void display_item(rpg_t *main, int i)
{
    if (item_bank[i].texte != NULL)
        sfRenderWindow_drawText(main->window->window,
            item_bank[i].texte, sfFalse);
    if (item_bank[i].sprite != NULL)
        sfRenderWindow_drawSprite(main->window->window,
            item_bank[i].sprite, sfFalse);
}

void display_inventory(rpg_t *main)
{
    if (main->inventory->state == 1) {
        sfRenderWindow_drawRectangleShape(main->window->window,
            main->inventory->inventory_back, sfFalse);
        for (int i = 0; item_bank[i].id != 0; i ++) {
            display_item(main, i);
        }
    }
}
