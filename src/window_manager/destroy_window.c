/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** destroy_window.c
*/

#include "../../include/rpg.h"

void destroy_window(rpg_t *main)
{
    sfRenderWindow_destroy(main->window->window);
    free(main->window->title);
    free(main->window);
}
