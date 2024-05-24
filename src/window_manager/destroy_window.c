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
        if (main->window->render_window != NULL) {
            sfRenderWindow_destroy(main->window->render_window);
            main->window->render_window = NULL;
        }
        if (main->window->title != NULL) {
            free(main->window->title);
            main->window->title = NULL;
        }
        free(main->window);
        main->window = NULL;
    }
    free(main);
}
