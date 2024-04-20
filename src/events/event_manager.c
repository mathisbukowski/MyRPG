/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** event_manager.c
*/

#include "../../include/rpg.h"

static void analyse_event(sfEvent event, rpg_t *main)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(main->window->window);
    if (event.type == sfEvtKeyPressed &&
        event.key.code == sfKeyF4 && (event.key.alt == sfTrue))
        sfRenderWindow_close(main->window->window);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
        sfRenderWindow_close(main->window->window);
}

void event_manager(rpg_t *main)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(main->window->window, &event))
        analyse_event(event, main);
}