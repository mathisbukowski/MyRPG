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

static void analyse_event(sfEvent event, rpg_t *main)
{

}

void event_manager(rpg_t *main)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(main->window->window, &event))
        execute_event(main, event.type);
}
