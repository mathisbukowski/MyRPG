/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** event_manager.c
*/

#include "rpg.h"

void close_window(const rpg_t *main)
{
    sfRenderWindow_close(main->window->window);
}

void event_manager(rpg_t *main)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(main->window->window, &event))
        if (event.type == sfEvtKeyPressed)
            handle_key_press(main, event.key.code);
        else
            execute_event(main, event.type);
}
