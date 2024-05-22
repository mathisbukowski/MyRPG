/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** create_window.c
*/

#include "rpg.h"

void create_window(const unsigned int width, const unsigned int height,
    const char *title, rpg_t *main)
{
    if (main->window != NULL) {
        main->window->mode.height = height;
        main->window->mode.width = width;
        main->window->isActive = sfTrue;
        main->window->isFullscreen = sfTrue;
        main->window->title = strdup(title);
        main->window->style = sfClose | sfResize;
        main->window->renderWindow = sfRenderWindow_create(main->window->mode,
        main->window->title, main->window->style, NULL);
        if (main->window->renderWindow == NULL) {
            free(main->window->title);
            free(main->window);
            main->window = NULL;
        }
    }
}
