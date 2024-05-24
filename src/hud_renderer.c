/*
** EPITECH PROJECT, 2024
** B-MUL-200-LIL-2-1-mypaint-raphael.richaud
** File description:
** hud_renderer.c
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "rpg.h"

static void render_buttons_in_menu(rpg_t *params,
    const menu_node_t *currMenuNode)
{
    button_node_t *currButtonNode = currMenuNode->menu->buttons;
    const sfVector2i mouse_pos = sfMouse_getPosition(
    (sfWindow *)params->window->renderWindow);

    while (currButtonNode != NULL) {
        sfRenderWindow_drawRectangleShape(params->window->renderWindow,
        currButtonNode->button->rect, NULL);
        handle_hover_and_click(currButtonNode, mouse_pos, params);
        if (currButtonNode->button->text != NULL)
            sfRenderWindow_drawText(params->window->renderWindow,
            currButtonNode->button->text, NULL);
        currButtonNode = currButtonNode->next;
    }
}

static void render_menu(const menu_node_t *currMenuNode, rpg_t *params)
{
    const sfVector2i mouse_pos = sfMouse_getPosition(
    (sfWindow *)params->window->renderWindow);
    menu_t *menu = currMenuNode->menu;

    if (menu->isHidden == 0) {
        check_menu_hover(menu, mouse_pos);
        handle_menu_hover(menu);
        sfRenderWindow_drawRectangleShape(params->window->renderWindow,
        menu->rect, NULL);
        if (menu->text != NULL)
            sfRenderWindow_drawText(params->window->renderWindow,
            menu->text, NULL);
        render_buttons_in_menu(params, currMenuNode);
    }
}

void render_scene(scene_t *scene, rpg_t *params)
{
    const menu_node_t *currMenuNode = scene->menus;

    while (currMenuNode != NULL) {
        if (currMenuNode->menu->isHidden == 0)
            render_menu(currMenuNode, params);
        currMenuNode = currMenuNode->next;
    }
}
