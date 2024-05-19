/*
** EPITECH PROJECT, 2024
** B-MUL-200-LIL-2-1-mypaint-raphael.richaud
** File description:
** hud_renderer.c
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "rpg.h"

static void render_buttons_in_menu(rpg_t *params, menu_node_t *currMenuNode)
{
    button_node_t *currButtonNode;
    sfVector2i mouse_pos = sfMouse_getPosition(
    (sfWindow *)params->window->window);

    currButtonNode = currMenuNode->menu->buttons;
    while (currButtonNode != NULL) {
        sfRenderWindow_drawRectangleShape(params->window->window,
        currButtonNode->button->rect, NULL);
        handle_hover_and_click(currButtonNode, mouse_pos, params);
        if (currButtonNode->button->text != NULL)
            sfRenderWindow_drawText(params->window->window,
            currButtonNode->button->text, NULL);
        currButtonNode = currButtonNode->next;
    }
}

static void render_menu(menu_node_t *currMenuNode, rpg_t *params)
{
    sfVector2i mouse_pos = sfMouse_getPosition(
    (sfWindow *)params->window->window);
    menu_t *menu = currMenuNode->menu;

    if (menu->isHidden == 0) {
        check_menu_hover(menu, mouse_pos);
        handle_menu_hover(menu);
        sfRenderWindow_drawRectangleShape(params->window->window,
        menu->rect, NULL);
        if (menu->text != NULL)
            sfRenderWindow_drawText(params->window->window,
            menu->text, NULL);
        render_buttons_in_menu(params, currMenuNode);
    }
}

void define_tools_menus(rpg_t *params, sfFont *font)
{
    create_menu((menu_params_t){"mainMenu", (sfVector2f){620, 400 },
    (sfVector2f){120, 123}, 0, sfTransparent, NULL, NULL, 0}
    , params);
    create_button((button_params_t){"HELLO", (sfVector2f){5, 55},
    (sfVector2f){45, 45}, sfBlue, sfBlue,
    &(text_infos_t){"pencil", font, (sfVector2f){5, 15},
    sfBlack, 13}, "mainMenu", NULL}, params);
    create_button((button_params_t){"sdlfksmf", (sfVector2f){70, 55},
    (sfVector2f){45, 45}, sfBlue, sfBlue,
    &(text_infos_t){"HELLO", font, (sfVector2f){5, 15},
    sfBlack, 13}, "mainMenu", NULL}, params);
}

void render_hud(rpg_t *params)
{
    menu_node_t *currMenuNode;

    currMenuNode = params->menus;
    while (currMenuNode != NULL) {
        if (currMenuNode->menu->isHidden == 0)
            render_menu(currMenuNode, params);
        currMenuNode = currMenuNode->next;
    }
}
