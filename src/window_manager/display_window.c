/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** display_window.c
*/

#include "rpg.h"

void display_window(rpg_t *main)
{
    sfRenderWindow_clear(main->window->renderWindow, sfWhite);
    entity_displayer(main);
    main->scene_manager->current->draw(main->scene_manager->current, main);
    sfRenderWindow_display(main->window->renderWindow);
}
