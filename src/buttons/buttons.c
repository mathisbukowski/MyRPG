/*
** EPITECH PROJECT, 2024
** B-MUL-200-LIL-2-1-mypaint-raphael.richaud
** File description:
** buttons.c
*/

#include "rpg.h"

static void is_clicked(const button_node_t *button_node, rpg_t *params)
{
    button_node_t *current = button_node->button->linked_menu->buttons;

    if (sfMouse_isButtonPressed(sfMouseLeft)){
        while (current != NULL) {
            current->button->is_selected = 0;
            current = current->next;
        }
        button_node->button->is_clicked = 1;
        button_node->button->is_selected = 1;
        if (button_node->button->action != NULL)
            button_node->button->action(params);
    }
}

void set_color_and_outline(const button_node_t *button_node)
{
    if (button_node->button->is_hover)
        sfRectangleShape_setFillColor(button_node->button->rect,
        button_node->button->hover_color);
    else
        sfRectangleShape_setFillColor(button_node->button->rect,
        button_node->button->color);
    if (button_node->button->is_selected)
        sfRectangleShape_setOutlineThickness(button_node->button->rect, 2);
    else
        sfRectangleShape_setOutlineThickness(button_node->button->rect, 0);
}

void handle_hover_and_click(const button_node_t *button_node,
    const sfVector2i mouse_pos, rpg_t *params)
{
    const sfFloatRect rect = sfRectangleShape_getGlobalBounds(
            button_node->button->rect);
    const sfVector2i pos = (sfVector2i){mouse_pos.x, mouse_pos.y};

    sfRectangleShape_setOutlineColor(button_node->button->rect, sfBlack);
    if (sfFloatRect_contains(&rect, (float)pos.x, (float)pos.y)) {
        button_node->button->is_hover = 1;
        is_clicked(button_node, params);
    } else
        button_node->button->is_hover = 0;
    set_color_and_outline(button_node);
}
