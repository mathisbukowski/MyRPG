/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** start_menu.c
*/

#include "rpg.h"

void define_start_button(rpg_t *params, sfFont *font,
    sfVector2f button_size, sfVector2f start_pos)
{
    create_button((button_params_t){"Start Game", start_pos,
    button_size, sfBlue, sfBlue,
    &(text_infos_t){"Start Game", font,
    (sfVector2f){button_size.x / 10, button_size.y / 4},
    sfBlack, 30}, "mainMenu", NULL}, params);
}

void define_options_button(rpg_t *params, sfFont *font,
    sfVector2f button_size, sfVector2f options_pos)
{
    create_button((button_params_t){"Settings", options_pos,
    button_size, sfBlue, sfBlue,
    &(text_infos_t){"Settings", font,
    (sfVector2f){button_size.x / 10, button_size.y / 4},
    sfBlack, 30}, "mainMenu", NULL}, params);
}

void define_exit_button(rpg_t *params, sfFont *font,
    sfVector2f button_size, sfVector2f exit_pos)
{
    create_button((button_params_t){"Exit", exit_pos,
    button_size, sfBlue, sfBlue,
    &(text_infos_t){"Exit", font,
    (sfVector2f){button_size.x / 10, button_size.y / 4},
    sfBlack, 30}, "mainMenu", NULL}, params);
}

void define_main_menu(rpg_t *params, sfFont *font)
{
    sfVector2f button_size = {400, 100};
    sfVector2f menu_size = {600, 600};
    sfVector2f menu_pos = {(float)(params->window->mode.width - 600) / 2,
    (float)(params->window->mode.height - 600) / 2};
    sfVector2f start_button_pos = {menu_size.x / 2 - button_size.x / 2
    , menu_size.y / 2 - 1.5 * button_size.y - 50};
    sfVector2f options_button_pos = {menu_size.x / 2 - button_size.x / 2,
    menu_size.y / 2 - 0.5 * button_size.y};
    sfVector2f exit_button_pos = {menu_size.x / 2 - button_size.x / 2,
    menu_size.y / 2 + 0.5 * button_size.y + 50};

    create_menu((menu_params_t){"mainMenu", menu_pos,
    menu_size, 0, sfTransparent, NULL, NULL, 0}, params);
    define_start_button(params, font, button_size, start_button_pos);
    define_options_button(params, font, button_size, options_button_pos);
    define_exit_button(params, font, button_size, exit_button_pos);
}
