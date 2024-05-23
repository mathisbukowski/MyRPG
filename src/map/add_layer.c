/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** add_layer.c
*/

#include "rpg.h"

int allocate_and_resize_layers(map_t *map)
{
    layer_t **temp = NULL;

    map->layer_count++;
    temp = realloc(map->layers, map->layer_count * sizeof(layer_t *));
    if (!temp)
        return -1;
    map->layers = temp;
    return 0;
}

int create_and_add_layer(map_t *map)
{
    layer_t *layer = create_layer(map->width, map->height, map->texture);

    if (!layer)
        return -1;
    map->layers[map->layer_count - 1] = layer;
    return 0;
}

void cleanup_memory(char *data_buffer, char **tile_data)
{
    if (data_buffer)
        free(data_buffer);
    if (tile_data) {
        for (int i = 0; tile_data[i]; i++)
            free(tile_data[i]);
        free(tile_data);
    }
}

int parse_and_configure_layer_data(layer_t *layer,
    char *layer_tag, sfTexture *texture)
{
    char *data_buffer = NULL;
    char **tile_data = NULL;
    int result = -1;

    data_buffer = extract_data_section(layer_tag);
    if (!data_buffer) {
        cleanup_memory(data_buffer, tile_data);
        return -1;
    }
    tile_data = my_str_to_word_array(data_buffer, ",");
    if (!tile_data) {
        cleanup_memory(data_buffer, tile_data);
        return -1;
    }
    result = configure_tiles(layer, tile_data, texture);
    cleanup_memory(data_buffer, tile_data);
    return result;
}

int add_layer(map_t *map, char *layer_tag)
{
    if (allocate_and_resize_layers(map) == -1)
        return -1;
    if (create_and_add_layer(map) == -1)
        return -1;
    return parse_and_configure_layer_data(map->layers[map->layer_count - 1],
    layer_tag, map->texture);
}
