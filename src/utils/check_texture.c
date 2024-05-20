/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** check_texture.c
*/

#include "rpg.h"
#include <stdio.h>

int check_texture(sfSprite *sprite, const sfTexture *texture)
{
    if (texture == NULL) {
        fprintf(stderr, "Error: file not found.\n");
        return 1;
    }
    sfSprite_setTexture(sprite, texture, sfTrue);
    return 0;
}
