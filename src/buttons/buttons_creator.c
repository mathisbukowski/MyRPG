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
    button_node_t *new_node;
    button_node_t *current;

    new_node = create_new_button_node(button);
    if (new_node == NULL)
        return 84;
    if (menu->buttons == NULL) {
        new_node->next = NULL;
        menu->buttons = new_node;
        return 0;
    }
    current = find_last_button_node(menu);
    new_node->next = current->next;
    current->next = new_node;
    return 0;
}

static int create_button_text(button_t *button, button_params_t button_params)
{
    sfVector2f text_pos = (sfVector2f){button->pos.x + button_params.text->pos.x,
        button->pos.y + button_params.text->pos.y};

    button->text = sfText_create();
    if (button->text == NULL)
        return 84;
    sfText_setString(button->text, button_params.text->text);
    sfText_setFont(button->text, button_params.text->font);
    sfText_setCharacterSize(button->text, button_params.text->size);
    sfText_setPosition(button->text, text_pos);
    sfText_setColor(button->text, button_params.text->color);
    return 0;
}

void init_button(button_t *button, const button_params_t button_params)
{
    button->rect = sfRectangleShape_create();
    button->pos = button_params.pos;
    button->color = button_params.color;
    button->hover_color = button_params.hover_color;
    button->action = button_params.action;
    button->is_hidden = 0;
    button->is_hover = 0;
    button->is_selected = 0;
    sfRectangleShape_setSize(button->rect, button_params.size);
    sfRectangleShape_setFillColor(button->rect, button->color);
}

void set_button_position(button_t *button, const sfVector2f linked_menu_pos,
    const button_params_t button_params)
{
    const sfVector2f button_pos = {linked_menu_pos.x + button_params.pos.x,
        linked_menu_pos.y + button_params.pos.y};

    button->pos = button_pos;
    sfRectangleShape_setPosition(button->rect, button->pos);
}

int set_text_and_linked_menu(button_t *button, button_params_t button_params,
    const rpg_t *params, scene_t *scene)
{
    button->text = NULL;
    if (button_params.text != NULL)
        if (create_button_text(button, button_params) == 84)
            return 84;
    button->linked_menu = find_menu_by_name(button_params.linked_menu_name,
        scene->menus);
    if (button->linked_menu == NULL) {
        free(button);
        return 84;
    }
    return 0;
}

int create_button(const button_params_t button_params,
    const rpg_t *params, scene_t *scene)
{
    button_t *button = malloc(sizeof(button_t));
    menu_t *linked_menu =
        find_menu_by_name(button_params.linked_menu_name, scene->menus);
    sfVector2f linked_menu_pos;

    if (button == NULL)
        return 84;
    if (linked_menu == NULL) {
        free(button);
        return 84;
    }
    linked_menu_pos = sfRectangleShape_getPosition(linked_menu->rect);
    init_button(button, button_params);
    set_button_position(button, linked_menu_pos, button_params);
    if (set_text_and_linked_menu(button, button_params, params, scene) == 84)
        return 84;
    if (add_button_to_menu(button, linked_menu) == 84)
        return 84;
    return 0;
}
