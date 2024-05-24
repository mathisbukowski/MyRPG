/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** create_layer.c
*/

#include "rpg.h"

int initialize_row(layer_t *layer, int row, int width, sfTexture *texture)
{
    layer->tiles[row] = malloc(width * sizeof(sfSprite *));
    if (!layer->tiles[row]) {
        return -1;
    }
    for (int j = 0; j < width; j++) {
        layer->tiles[row][j] = sfSprite_create();
        if (!layer->tiles[row][j]) {
            return -1;
        }
        sfSprite_setTexture(layer->tiles[row][j], texture, sfTrue);
    }
    return 0;
}

int initialize_layer_tiles(layer_t *layer, int width, int height,
    sfTexture *texture)
{
    for (int i = 0; i < height; i++) {
        if (initialize_row(layer, i, width, texture) == -1) {
            free_layer_tiles(layer, i + 1);
            return -1;
        }
    }
    return 0;
}

layer_t *create_layer(int width, int height, sfTexture *texture)
{
    layer_t *layer = malloc(sizeof(layer_t));

    if (!layer)
        return NULL;
    layer->width = width;
    layer->height = height;
    layer->tiles = malloc(height * sizeof(sfSprite **));
    if (!layer->tiles) {
        free(layer);
        return NULL;
    }
    if (initialize_layer_tiles(layer, width, height, texture) == -1) {
        free(layer);
        return NULL;
    }
    return layer;
}
