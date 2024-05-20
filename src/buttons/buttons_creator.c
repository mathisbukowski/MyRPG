/*
** EPITECH PROJECT, 2024
** B-MUL-200-LIL-2-1-mypaint-raphael.richaud
** File description:
** buttons_creator.c
*/

#include "rpg.h"

static button_node_t *create_new_button_node(button_t *button)
{
    button_node_t *new_node = malloc(sizeof(button_node_t));

    if (new_node == NULL)
        return NULL;
    new_node->button = button;
    new_node->next = NULL;
    return new_node;
}

static button_node_t *find_last_button_node(menu_t *menu)
{
    button_node_t *curr = menu->buttons;

    while (curr != NULL && curr->next != NULL)
        curr = curr->next;
    return curr;
}

static int add_button_to_menu(button_t *button, menu_t *menu)
{
    button_node_t *newNode;
    button_node_t *current;

    newNode = create_new_button_node(button);
    if (newNode == NULL)
        return 84;
    if (menu->buttons == NULL) {
        newNode->next = NULL;
        menu->buttons = newNode;
        return 0;
    }
    current = find_last_button_node(menu);
    newNode->next = current->next;
    current->next = newNode;
    return 0;
}

static int create_button_text(button_t *button, button_params_t buttonParams)
{
    sfVector2f textPos = (sfVector2f){button->pos.x + buttonParams.text->pos.x,
        button->pos.y + buttonParams.text->pos.y};

    button->text = sfText_create();
    if (button->text == NULL)
        return 84;
    sfText_setString(button->text, buttonParams.text->text);
    sfText_setFont(button->text, buttonParams.text->font);
    sfText_setCharacterSize(button->text, buttonParams.text->size);
    sfText_setPosition(button->text, textPos);
    sfText_setColor(button->text, buttonParams.text->color);
    return 0;
}

void init_button(button_t *button, const button_params_t buttonParams)
{
    button->rect = sfRectangleShape_create();
    button->pos = buttonParams.pos;
    button->color = buttonParams.color;
    button->hoverColor = buttonParams.hoverColor;
    button->action = buttonParams.action;
    button->isHidden = 0;
    button->isHover = 0;
    button->isSelected = 0;
    sfRectangleShape_setSize(button->rect, buttonParams.size);
    sfRectangleShape_setFillColor(button->rect, button->color);
}

void set_button_position(button_t *button, const sfVector2f linkedMenuPos,
    const button_params_t buttonParams)
{
    const sfVector2f buttonPos = {linkedMenuPos.x + buttonParams.pos.x,
                            linkedMenuPos.y + buttonParams.pos.y};

    button->pos = buttonPos;
    sfRectangleShape_setPosition(button->rect, button->pos);
}

int set_text_and_linked_menu(button_t *button, button_params_t buttonParams,
    const rpg_t *params)
{
    button->text = NULL;
    if (buttonParams.text != NULL)
        if (create_button_text(button, buttonParams) == 84)
            return 84;
    button->linkedMenu = find_menu_by_name(buttonParams.linkedMenuName,
        params->menus);
    if (button->linkedMenu == NULL) {
        free(button);
        return 84;
    }
    return 0;
}

int create_button(const button_params_t buttonParams, const rpg_t *params)
{
    button_t *button = malloc(sizeof(button_t));
    menu_t *linkedMenu =
        find_menu_by_name(buttonParams.linkedMenuName, params->menus);
    const sfVector2f linkedMenuPos =
        sfRectangleShape_getPosition(linkedMenu->rect);

    if (button == NULL)
        return 84;
    if (linkedMenu == NULL) {
        free(button);
        return 84;
    }
    init_button(button, buttonParams);
    set_button_position(button, linkedMenuPos, buttonParams);
    if (set_text_and_linked_menu(button, buttonParams, params) == 84)
        return 84;
    if (add_button_to_menu(button, linkedMenu) == 84)
        return 84;
    return 0;
}
