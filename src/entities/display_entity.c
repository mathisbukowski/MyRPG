/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** display_sprite.c
*/

#include "rpg.h"

void display_entity(rpg_t *main, char *name)
{
    if (!sfRenderWindow_isOpen(main->window->renderWindow))
        return;
    for (entity_t *curr = main->entities; curr != NULL; curr = curr->next)
        if (curr->name != NULL && strcmp(curr->name, name) == 0
        && curr->sprite && curr->state) {
            manage_clock(curr);
            sfRenderWindow_drawSprite(main->window->renderWindow,
            curr->sprite, NULL);
            break;
        }
}

void entities_displayer(rpg_t *main)
{
    if (!sfRenderWindow_isOpen(main->window->renderWindow))
        return;
    for (entity_t *curr = main->entities; curr != NULL; curr = curr->next)
        if (curr->sprite && curr->state && strcmp(curr->name, "player") != 0) {
            manage_clock(curr);
            sfRenderWindow_drawSprite(main->window->renderWindow,
                curr->sprite, NULL);
        }
}
