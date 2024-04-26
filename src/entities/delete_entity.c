/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** delete_sprite.c
*/

#include "rpg.h"

void free_entities(entity_t *entities)
{
    entity_t *tmp = NULL;

    while (entities != NULL) {
        tmp = entities;
        entities = entities->next;
        if (tmp->sprite)
            sfSprite_destroy(tmp->sprite);
        if (tmp->texture)
            sfTexture_destroy(tmp->texture);
        if (tmp->name)
            free(tmp->name);
        free(tmp);
    }
}
