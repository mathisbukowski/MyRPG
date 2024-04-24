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
    sfVector2i mouse_pos = sfMouse_getPosition((sfWindow *)params->window->window);

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
    sfVector2i mouse_pos = sfMouse_getPosition((sfWindow *)params->window->window);
    menu_t *menu = currMenuNode->menu;

    if (menu->isHidden == 0) {
        check_menu_hover(menu, mouse_pos);
        handle_menu_hover(menu);
        sfRenderWindow_drawRectangleShape(params->window->window, menu->rect, NULL);
        if (menu->text != NULL)
            sfRenderWindow_drawText(params->window->window, menu->text, NULL);
        render_buttons_in_menu(params, currMenuNode);
    }
}

void define_tools_menus(rpg_t *params, sfFont *font)
{
    create_menu((menu_params_t){"mainMenu", (sfVector2f){0, 0 },
        (sfVector2f){1920, 75}, 0, sfColor_fromRGB(97, 97, 97), NULL, NULL, 0}
        , params);
    create_menu((menu_params_t){"toolsSelector", (sfVector2f){0, 0 },
        (sfVector2f){55, 200}, 2, sfCyan, NULL, &(text_infos_t)
        {"Tools", font, (sfVector2f) {5, 15}, sfBlack, 18}, 1}, params);
}

static void define_colors_menus2(rpg_t *params, sfFont *font)
{
    create_button((button_params_t){"whiteBtn", (sfVector2f){5, 110},
        (sfVector2f){20, 20}, sfWhite, sfColor_fromRGB(200, 200, 200), NULL,
        "colorsSelector"}, params);
    create_button((button_params_t){"yellowBtn", (sfVector2f){30, 110},
        (sfVector2f){20, 20}, sfYellow, sfColor_fromRGB(180, 180, 0), NULL,
        "colorsSelector"}, params);
}

void define_colors_menus(rpg_t *params, sfFont *font)
{
    create_menu((menu_params_t){"colorsSelector", (sfVector2f){0, 0 },
        (sfVector2f){55, 200}, 2, sfCyan, NULL, &(text_infos_t)
        {"Colors", font, (sfVector2f) {5, 15}, sfBlack, 18}, 1}, params);
    create_menu((menu_params_t){"colorsMenu", (sfVector2f){75, 10 },
        (sfVector2f){55, 55}, 1, sfCyan, "colorsSelector", &(text_infos_t)
        {"Colors", font, (sfVector2f){5, 15}, sfBlack, 18}, 0}, params);
    define_colors_menus2(params, font);
}

static void define_sizes_menus2(rpg_t *params, sfFont *font)
{
    create_button((button_params_t){"hugeButton", (sfVector2f){5, 205},
    (sfVector2f){45, 45}, sfColor_fromRGB(200, 200, 200), sfColor_fromRGB
    (180, 180, 180), &(text_infos_t){"huge", font, (sfVector2f){10, 15},
    sfBlack, 13}, "sizeSelector"}, params);
    create_button((button_params_t){"giantButton", (sfVector2f){5, 255},
    (sfVector2f){45, 45}, sfColor_fromRGB(200, 200, 200), sfColor_fromRGB
    (180, 180, 180), &(text_infos_t){"giant", font, (sfVector2f){8, 14},
    sfBlack, 15}, "sizeSelector"}, params);
}

void define_sizes_menus(rpg_t *params, sfFont *font)
{
    create_menu((menu_params_t){"sizeSelector", (sfVector2f){0, 0 },
    (sfVector2f){55, 320}, 2, sfCyan, NULL, &(text_infos_t)
    {"Sizes", font, (sfVector2f) {5, 15}, sfBlack, 18}, 1}, params);
    create_menu((menu_params_t){"sizeMenu", (sfVector2f){140, 10 },
    (sfVector2f){55, 55}, 1, sfCyan, "sizeSelector", &(text_infos_t)
    {"Sizes", font, (sfVector2f){5, 15}, sfBlack, 18}, 0}, params);
    define_sizes_menus2(params, font);
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
