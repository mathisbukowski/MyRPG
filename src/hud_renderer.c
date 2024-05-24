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
    const menu_node_t *curr_menu_node)
{
    button_node_t *currButtonNode = curr_menu_node->menu->buttons;
    const sfVector2i mouse_pos = sfMouse_getPosition(
    (sfWindow *)params->window->render_window);

    while (currButtonNode != NULL) {
        sfRenderWindow_drawRectangleShape(params->window->render_window,
        currButtonNode->button->rect, NULL);
        handle_hover_and_click(currButtonNode, mouse_pos, params);
        if (currButtonNode->button->text != NULL)
            sfRenderWindow_drawText(params->window->render_window,
            currButtonNode->button->text, NULL);
        currButtonNode = currButtonNode->next;
    }
}

static void render_menu(const menu_node_t *curr_menu_node, rpg_t *params)
{
    const sfVector2i mouse_pos = sfMouse_getPosition(
    (sfWindow *)params->window->render_window);
    menu_t *menu = curr_menu_node->menu;

    if (menu->is_hidden == 0) {
        check_menu_hover(menu, mouse_pos);
        handle_menu_hover(menu);
        sfRenderWindow_drawRectangleShape(params->window->render_window,
        menu->rect, NULL);
        if (menu->text != NULL)
            sfRenderWindow_drawText(params->window->render_window,
            menu->text, NULL);
        render_buttons_in_menu(params, curr_menu_node);
    }
}

void render_scene(scene_t *scene, rpg_t *params)
{
    const menu_node_t *curr_menu_node = scene->menus;

    while (curr_menu_node != NULL) {
        if (curr_menu_node->menu->is_hidden == 0)
            render_menu(curr_menu_node, params);
        curr_menu_node = curr_menu_node->next;
    }
}
