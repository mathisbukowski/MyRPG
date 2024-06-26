/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** display_window.c
*/

#include "rpg.h"

void display_window(rpg_t *main)
{
    float elapsed = get_elapsed_time(main);

    UNUSED(elapsed);
    sfRenderWindow_clear(main->window->renderWindow, sfBlack);
    draw_map(main, main->map);
    sfRenderWindow_setView(main->window->renderWindow,
    sfRenderWindow_getDefaultView(main->window->renderWindow));
    main->scene_manager->current->draw(main->scene_manager->current, main);
    display_inventory(main);
    update_fps(main);
    sfRenderWindow_display(main->window->renderWindow);
}
