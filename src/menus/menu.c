/*
** EPITECH PROJECT, 2024
** B-MUL-200-LIL-2-1-mypaint-raphael.richaud
** File description:
** menu.c
*/

#include "rpg.h"

static int add_menu_to_scene(scene_t *scene, menu_t *menu)
{
    menu_node_t *new_node = malloc(sizeof(menu_node_t));
    menu_node_t *current = NULL;

    if (new_node == NULL)
        return 84;
    new_node->menu = menu;
    new_node->next = NULL;
    if (scene->menus == NULL)
        scene->menus = new_node;
    else {
        current = scene->menus;
        while (current->next != NULL)
            current = current->next;
        current->next = new_node;
    }
    sort_menus(&scene->menus);
    return 0;
}

void check_menu_hover(menu_t *menu, const sfVector2i mouse_pos)
{
    const sfFloatRect rect = sfRectangleShape_getGlobalBounds(menu->rect);
    const sfVector2i pos = (sfVector2i){mouse_pos.x, mouse_pos.y};

    if (sfFloatRect_contains(&rect, (float)pos.x, (float)pos.y) ||
        (menu->sub_menu != NULL && menu->sub_menu->is_hover == 1)) {
        menu->is_hover = 1;
    } else {
        menu->is_hover = 0;
    }
}

menu_t *find_menu_by_name(const char *name, menu_node_t *head)
{
    menu_node_t *current = head;

    while (current != NULL) {
        if (my_strcmp(current->menu->name, name) == 0)
            return current->menu;
        current = current->next;
    }
    return NULL;
}

static int create_menu_text(menu_t *menu, const menu_params_t menu_params)
{
    const sfVector2f text_pos = (sfVector2f){menu_params.pos.x +
        menu_params.text->pos.x, menu_params.pos.y + menu_params.text->pos.y};

    menu->text = sfText_create();
    if (menu->text == NULL)
        return 84;
    sfText_setString(menu->text, menu_params.text->text);
    sfText_setFont(menu->text, menu_params.text->font);
    sfText_setCharacterSize(menu->text, menu_params.text->size);
    sfText_setPosition(menu->text, text_pos);
    sfText_setColor(menu->text, menu_params.text->color);
    return 0;
}

static void init_variables(menu_t *menu, const menu_params_t menu_params,
    rpg_t *params, scene_t *scene)
{
    menu->name = menu_params.name;
    menu->pos = menu_params.pos;
    menu->size = menu_params.size;
    menu->y_index = menu_params.y_index;
    menu->is_hover = 0;
    menu->is_clicked = 0;
    menu->is_hidden = menu_params.is_hidden;
    menu->is_open = 0;
    menu->buttons = NULL;
    menu->rect = sfRectangleShape_create();
    menu->text = NULL;
    if (menu_params.text != NULL)
        create_menu_text(menu, menu_params);
    menu->sub_menu = NULL;
    if (menu_params.sub_menu_name != NULL)
        menu->sub_menu = find_menu_by_name(menu_params.sub_menu_name,
    scene->menus);
    sfRectangleShape_setPosition(menu->rect, menu_params.pos);
    sfRectangleShape_setSize(menu->rect, menu_params.size);
    sfRectangleShape_setFillColor(menu->rect, menu_params.color);
}

void handle_menu_hover(const menu_t *menu)
{
    if (menu->is_hover == 1) {
        if (menu->sub_menu != NULL)
            menu->sub_menu->is_hidden = 0;
    } else {
        if (menu->sub_menu != NULL)
            menu->sub_menu->is_hidden = 1;
    }
}

static void set_sub_menu(menu_t *menu)
{
    const sfVector2f sub_menu_pos = (sfVector2f){menu->sub_menu->pos.x,
        menu->sub_menu->pos.y};
    const sfVector2f sub_menutext_pos = (sfVector2f){sub_menu_pos.x + 5,
        sub_menu_pos.y + 15};

    menu->sub_menu->parent_menu = menu;
    menu->sub_menu->pos.x += menu->pos.x;
    menu->sub_menu->pos.y += menu->pos.y;
    sfText_setPosition(menu->sub_menu->text, sub_menutext_pos);
    sfRectangleShape_setPosition(menu->sub_menu->rect, menu->sub_menu->pos);
}

int create_menu(const menu_params_t menu_params, scene_t *scene, rpg_t *params)
{
    menu_t *menu = malloc(sizeof(menu_t));

    if (menu == NULL)
        return 84;
    init_variables(menu, menu_params, params, scene);
    if (menu->sub_menu != NULL)
        set_sub_menu(menu);
    add_menu_to_scene(scene, menu);
    return 0;
}
