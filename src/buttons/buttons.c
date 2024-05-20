/*
** EPITECH PROJECT, 2024
** B-MUL-200-LIL-2-1-mypaint-raphael.richaud
** File description:
** buttons.c
*/

#include "rpg.h"

static void is_clicked(const button_node_t *buttonNode, rpg_t *params)
{
    button_node_t *current = buttonNode->button->linkedMenu->buttons;

    if (sfMouse_isButtonPressed(sfMouseLeft)){
        while (current != NULL) {
            current->button->isSelected = 0;
            current = current->next;
        }
        buttonNode->button->isClicked = 1;
        buttonNode->button->isSelected = 1;
        if (buttonNode->button->action != NULL)
            buttonNode->button->action(params);
    }
}

void set_color_and_outline(const button_node_t *buttonNode)
{
    if (buttonNode->button->isHover)
        sfRectangleShape_setFillColor(buttonNode->button->rect,
        buttonNode->button->hoverColor);
    else
        sfRectangleShape_setFillColor(buttonNode->button->rect,
        buttonNode->button->color);
    if (buttonNode->button->isSelected)
        sfRectangleShape_setOutlineThickness(buttonNode->button->rect, 2);
    else
        sfRectangleShape_setOutlineThickness(buttonNode->button->rect, 0);
}

void handle_hover_and_click(const button_node_t *buttonNode,
    const sfVector2i mousePos, rpg_t *params)
{
    const sfFloatRect rect = sfRectangleShape_getGlobalBounds(
            buttonNode->button->rect);
    const sfVector2i pos = (sfVector2i){mousePos.x, mousePos.y};

    sfRectangleShape_setOutlineColor(buttonNode->button->rect, sfBlack);
    if (sfFloatRect_contains(&rect, (float)pos.x, (float)pos.y)) {
        buttonNode->button->isHover = 1;
        is_clicked(buttonNode, params);
    } else
        buttonNode->button->isHover = 0;
    set_color_and_outline(buttonNode);
}
