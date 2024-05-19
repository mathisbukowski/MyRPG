/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** display_window.c
*/

#include "rpg.h"

void display_window(rpg_t *main)
{
    sfRenderWindow_clear(main->window->window, sfWhite);
    entity_displayer(main);
    render_hud(main);
    sfRenderWindow_display(main->window->window);
}
