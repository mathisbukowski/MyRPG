/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** event_manager.c
*/

#include "../../include/rpg.h"

void close_window(rpg_t *main)
{
    sfRenderWindow_close(main->window->window);
}

void event_manager(rpg_t *main)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(main->window->window, &event))
        execute_event(main, event.type);
}
