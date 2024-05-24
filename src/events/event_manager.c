/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** event_manager.c
*/

#include "rpg.h"

void close_window(rpg_t *main)
{
    sfRenderWindow_close(main->window->render_window);
}

static void handle_player_events(rpg_t *main)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ))
        up_action(main);
    if (sfKeyboard_isKeyPressed(sfKeyS))
        down_action(main);
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        left_action(main);
    if (sfKeyboard_isKeyPressed(sfKeyD))
        right_action(main);
    if (sfKeyboard_isKeyPressed(sfKeyP))
        close_window(main);
}

void event_manager(rpg_t *main)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(main->window->render_window, &event)) {
        if (event.type == sfEvtKeyPressed)
            handle_key_press(main, event.key.code);
        else
            execute_event(main, event.type);
    }
    handle_player_events(main);
}
