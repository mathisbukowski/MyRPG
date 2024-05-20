/*
** EPITECH PROJECT, 2024
** B-MUL-200-LIL-2-1-mypaint-raphael.richaud
** File description:
** menu.c
*/

#include "rpg.h"

static int add_menu_to_hud(rpg_t *params, menu_t *menu)
{
    menu_node_t *newNode = malloc(sizeof(menu_node_t));
    menu_node_t *current;

    if (newNode == NULL)
        return 84;
    newNode->menu = menu;
    newNode->next = NULL;
    if (params->menus == NULL)
        params->menus = newNode;
    else {
        current = params->menus;
        while (current != NULL && current->next != NULL)
            current = current->next;
        if (current != NULL)
            current->next = newNode;
    }
    sort_menus(&params->menus);
    return 0;
}

void check_menu_hover(menu_t *menu, const sfVector2i mousePos)
{
    const sfFloatRect rect = sfRectangleShape_getGlobalBounds(menu->rect);
    const sfVector2i pos = (sfVector2i){mousePos.x, mousePos.y};

    if (sfFloatRect_contains(&rect, (float)pos.x, (float)pos.y) ||
        (menu->subMenu != NULL && menu->subMenu->isHover == 1)) {
        menu->isHover = 1;
    } else {
        menu->isHover = 0;
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

static int create_menu_text(menu_t *menu, const menu_params_t menuParams)
{
    const sfVector2f textPos = (sfVector2f){menuParams.pos.x +
        menuParams.text->pos.x, menuParams.pos.y + menuParams.text->pos.y};

    menu->text = sfText_create();
    if (menu->text == NULL)
        return 84;
    sfText_setString(menu->text, menuParams.text->text);
    sfText_setFont(menu->text, menuParams.text->font);
    sfText_setCharacterSize(menu->text, menuParams.text->size);
    sfText_setPosition(menu->text, textPos);
    sfText_setColor(menu->text, menuParams.text->color);
    return 0;
}

static void init_variables(menu_t *menu, const menu_params_t menuParams,
    rpg_t *params)
{
    menu->name = menuParams.name;
    menu->pos = menuParams.pos;
    menu->size = menuParams.size;
    menu->y_index = menuParams.y_index;
    menu->isHover = 0;
    menu->isClicked = 0;
    menu->isHidden = menuParams.isHidden;
    menu->isOpen = 0;
    menu->buttons = NULL;
    menu->rect = sfRectangleShape_create();
    menu->text = NULL;
    if (menuParams.text != NULL)
        create_menu_text(menu, menuParams);
    menu->subMenu = NULL;
    if (menuParams.subMenuName != NULL)
        menu->subMenu = find_menu_by_name(menuParams.subMenuName,
                                            params->menus);
    sfRectangleShape_setPosition(menu->rect, menuParams.pos);
    sfRectangleShape_setSize(menu->rect, menuParams.size);
    sfRectangleShape_setFillColor(menu->rect, menuParams.color);
}

void handle_menu_hover(const menu_t *menu)
{
    if (menu->isHover == 1) {
        if (menu->subMenu != NULL)
            menu->subMenu->isHidden = 0;
    } else {
        if (menu->subMenu != NULL)
            menu->subMenu->isHidden = 1;
    }
}

static void set_submenu(menu_t *menu)
{
    const sfVector2f subMenuPos = (sfVector2f){menu->subMenu->pos.x,
        menu->subMenu->pos.y};
    const sfVector2f subMenuTextPos = (sfVector2f){subMenuPos.x + 5,
        subMenuPos.y + 15};

    menu->subMenu->parentMenu = menu;
    menu->subMenu->pos.x += menu->pos.x;
    menu->subMenu->pos.y += menu->pos.y;
    sfText_setPosition(menu->subMenu->text, subMenuTextPos);
    sfRectangleShape_setPosition(menu->subMenu->rect, menu->subMenu->pos);
}

int create_menu(const menu_params_t menuParams, rpg_t *params)
{
    menu_t *menu = malloc(sizeof(menu_t));

    if (menu == NULL)
        return 84;
    init_variables(menu, menuParams, params);
    if (menu->subMenu != NULL)
        set_submenu(menu);
    add_menu_to_hud(params, menu);
    return 0;
}
