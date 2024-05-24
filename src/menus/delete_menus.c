/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** delete_menus.c
*/

#include "rpg.h"

void destroy_button(button_node_t *buttonNode)
{
    if (buttonNode == NULL)
        return;
    if (buttonNode->button != NULL) {
        if (buttonNode->button->rect != NULL)
            sfRectangleShape_destroy(buttonNode->button->rect);
        if (buttonNode->button->text != NULL)
            sfText_destroy(buttonNode->button->text);
        free(buttonNode->button);
    }
    destroy_button(buttonNode->next);
    free(buttonNode);
}

void destroy_menu(menu_node_t *menuNode)
{
    menu_t *menu;

    if (menuNode == NULL)
        return;
    menu = menuNode->menu;
    if (menu != NULL) {
        if (menu->rect != NULL)
            sfRectangleShape_destroy(menu->rect);
        if (menu->text != NULL)
            sfText_destroy(menu->text);
        if (menu->buttons != NULL)
            destroy_button(menu->buttons);
        free(menu);
    }
    destroy_menu(menuNode->next);
    free(menuNode);
}
