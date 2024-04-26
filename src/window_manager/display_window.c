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
    sfRenderWindow_display(main->window->window);
}
