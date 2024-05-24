/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** free_map.c
*/

#include "rpg.h"

void free_coords(layer_t *layer)
{
    for (int i = 0; i < layer->height; i++) {
        free(layer->coords[i]);
    }
    free(layer->coords);
}

void free_tile_layer(sfSprite ***tiles, int height, int width)
{
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++)
            sfSprite_destroy(tiles[i][j]);
        free(tiles[i]);
    }
    free(tiles);
}

void free_layer(layer_t *layer)
{
    if (layer) {
        free_tile_layer(layer->tiles, layer->height, layer->width);
        if (layer->coords)
            free_coords(layer);
        free(layer);
    }
}

void free_map(map_t *map)
{
    if (!map)
        return;
    for (int l = 0; l < map->layer_count; l++)
        free_layer(map->layers[l]);
    free(map->layers);
    if (map->texture)
        sfTexture_destroy(map->texture);
    free(map);
}
