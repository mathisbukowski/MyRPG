/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** display_window.c
*/

#include "rpg.h"

void display_window(rpg_t *main)
{
    sfRenderWindow_clear(main->window->window, sfBlack);
    draw_map(main, main->map);
    sfRenderWindow_setView(main->window->window,
    sfRenderWindow_getDefaultView(main->window->window));
    entity_displayer(main);
    main->scene_manager->current->draw(main->scene_manager->current, main);
    sfRenderWindow_display(main->window->renderWindow);
}
