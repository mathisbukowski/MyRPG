/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** configure_tiles.c
*/

#include "rpg.h"

void configure_tile(tile_config_t *config)
{
    int tile_width = 16;
    int tile_height = 16;
    int x = config->j * tile_width;
    int y = config->i * tile_height;
    sfVector2u size = sfTexture_getSize(config->texture);
    int tiles_per_row = size.x / tile_width;
    sfIntRect rect = {((config->tile_id - 1) % tiles_per_row) * tile_width,
    ((config->tile_id - 1) / tiles_per_row) * tile_height,
    tile_width, tile_height};

    sfSprite_setPosition(config->layer->tiles[config->i][config->j],
    (sfVector2f){x, y});
    sfSprite_setTextureRect(config->layer->tiles[config->i][config->j],
    config->tile_id ? rect : (sfIntRect){0, 0, 0, 0});
}

int configure_tiles(layer_t *layer, char **tile_data, sfTexture *texture)
{
    int tile_id = 0;
    int index = 0;
    tile_config_t config = { .layer = layer, .texture = texture };

    layer->coords = malloc(sizeof(tile_t *) * layer->height);
    for (int x = 0; x < layer->height; x++)
        layer->coords[x] = malloc(sizeof(tile_t) * layer->width);
    for (int i = 0; i < layer->height; i++)
        for (int j = 0; j < layer->width; j++) {
            tile_id = (int)strtol(tile_data[index], NULL, 10);
            config.tile_id = tile_id;
            config.i = i;
            config.j = j;
            configure_tile(&config);
            layer->coords[i]->data = tile_id;
            layer->coords[i][j].x = config.j * 16;
            layer->coords[i][j].y = config.i * 16;
            index++;
        }
    return 0;
}
