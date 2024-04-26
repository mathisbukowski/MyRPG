/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** display_sprite.c
*/

#include "rpg.h"

void sprite_displayer(rpg_t *main)
{
    sprite_t *current = main->sprites;

    if (!sfRenderWindow_isOpen(main->window->window))
        return;
    while (current != NULL) {
        if (current->sprite && current->state == true)
            sfRenderWindow_drawSprite(main->window->window,
            current->sprite, NULL);
        current = current->next;
    }
}
