/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** delete_sprite.c
*/

#include "rpg.h"

void free_sprites(sprite_t *sprites)
{
    sprite_t *tmp = NULL;

    while (sprites != NULL) {
        tmp = sprites;
        sprites = sprites->next;
        if (tmp->sprite)
            sfSprite_destroy(tmp->sprite);
        if (tmp->texture)
            sfTexture_destroy(tmp->texture);
        if (tmp->name)
            free(tmp->name);
        free(tmp);
    }
}
