/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** display_inventory.c
*/

#include "rpg.h"

char *get_value_item(int x)
{
    char *buffer = malloc(sizeof(char) * 9);

    sprintf(buffer, "%d", item_bank[x].quantity);
    return buffer;
}

void change_inventory_state(rpg_t *main)
{
    main->inventory->state *= -1;
}

void display_item(rpg_t *main, int i, sfVector2f base_position)
{
    sfVector2f box_size = {60, 60};
    sfVector2f box_position = {base_position.x + (box_size.x + 12) * (i % 5),
    base_position.y + (box_size.y + 12) * (i / 5)};
    sfVector2f item_position = {box_position.x + box_size.x / 2,
    box_position.y + box_size.y / 2};

    if (item_bank[i].sprite != NULL) {
        sfSprite_setPosition(item_bank[i].sprite, (sfVector2f){
        item_position.x+ 90, item_position.y + 140});
        sfRenderWindow_drawSprite(main->window->renderWindow,
        item_bank[i].sprite, NULL);
    }
    if (item_bank[i].texte != NULL) {
        sfText_setPosition(item_bank[i].texte, (sfVector2f){
        box_position.x + 110, box_position.y + 160});
        sfRenderWindow_drawText(main->window->renderWindow, item_bank[i].texte,
        NULL);
    }
}

void display_inventory(rpg_t *main)
{
    sfVector2u win_size = sfRenderWindow_getSize(main->window->renderWindow);
    sfVector2f inventory_size = sfRectangleShape_getSize(
    main->inventory->inventory_back);
    sfVector2f middle_position;
    sfVector2f base_position;

    if (main->inventory->state == 1 && strcmp(
        main->scene_manager->current->name, "gameScene") == 0) {
        middle_position.x = (win_size.x - inventory_size.x) / 3;
        middle_position.y = (win_size.y - inventory_size.y) / 2;
        sfRectangleShape_setPosition(main->inventory->inventory_back,
        middle_position);
        sfRenderWindow_drawRectangleShape(main->window->renderWindow,
        main->inventory->inventory_back, NULL);
        base_position.x = middle_position.x + 20;
        base_position.y = middle_position.y + 20;
        for (int i = 0; item_bank[i].id != 0; i++) {
            display_item(main, i, base_position);
        }
    }
}
