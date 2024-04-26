/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** display_sprite.c
*/

#include "rpg.h"

void entity_displayer(rpg_t *main)
{
    entity_t *current = main->entities;

    if (!sfRenderWindow_isOpen(main->window->window))
        return;
    while (current != NULL) {
        if (current->sprite && current->state == true)
            sfRenderWindow_drawSprite(main->window->window,
            current->sprite, NULL);
        current = current->next;
    }
}
