/*
** EPITECH PROJECT, 2024
** myrpg
** File description:
** set_window_fps.c
*/

#include "rpg.h"

void set_window_fps_to_sixty(rpg_t *main)
{
    sfRenderWindow_setFramerateLimit(main->window->render_window, 60);
}

void set_window_fps_to_hundred(rpg_t *main)
{
    sfRenderWindow_setFramerateLimit(main->window->render_window, 100);
}

void set_window_fps_to_hundred_twenty(rpg_t *main)
{
    sfRenderWindow_setFramerateLimit(main->window->render_window, 120);
}
