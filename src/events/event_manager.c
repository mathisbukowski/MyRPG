/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** event_manager.c
*/

#include "rpg.h"

void close_window(rpg_t *main)
{
    sfRenderWindow_close(main->window->renderWindow);
}

void event_manager(rpg_t *main)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(main->window->renderWindow, &event))
        if (event.type == sfEvtKeyPressed)
            handle_key_press(main, event.key.code);
        else
            execute_event(main, event.type);
}
