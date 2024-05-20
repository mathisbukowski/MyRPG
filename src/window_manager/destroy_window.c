/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** destroy_window.c
*/

#include "rpg.h"

void destroy_window(rpg_t *main)
{
    if (main != NULL && main->window != NULL) {
        if (main->window->window != NULL) {
            sfRenderWindow_destroy(main->window->window);
            main->window->window = NULL;
        }
        if (main->window->title != NULL) {
            free(main->window->title);
            main->window->title = NULL;
        }
        free(main->window);
        main->window = NULL;
    }
}
