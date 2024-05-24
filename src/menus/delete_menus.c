/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** delete_menus.c
*/

#include "rpg.h"

void destroy_button(button_node_t *button_node)
{
    if (button_node == NULL)
        return;
    if (button_node->button != NULL) {
        if (button_node->button->rect != NULL)
            sfRectangleShape_destroy(button_node->button->rect);
        if (button_node->button->text != NULL)
            sfText_destroy(button_node->button->text);
        free(button_node->button);
    }
    destroy_button(button_node->next);
    free(button_node);
}

void destroy_menu(menu_node_t *menu_node)
{
    menu_t *menu;

    if (menu_node == NULL)
        return;
    menu = menu_node->menu;
    if (menu != NULL) {
        if (menu->rect != NULL)
            sfRectangleShape_destroy(menu->rect);
        if (menu->text != NULL)
            sfText_destroy(menu->text);
        if (menu->buttons != NULL)
            destroy_button(menu->buttons);
        free(menu);
    }
    destroy_menu(menu_node->next);
    free(menu_node);
}
