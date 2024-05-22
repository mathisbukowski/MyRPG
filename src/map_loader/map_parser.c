/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** map_parser.c
*/

#include "rpg.h"

map_t *allocate_map(void)
{
    map_t *map = malloc(sizeof(map_t));
    if (map == NULL) {
        return NULL;
    }
    map->layer_count = 0;
    map->layers = NULL;
    return map;
}

int extract_map_dimensions(map_t *map, char *map_tag)
{
    map->width = extract_attribute(map_tag, "width");
    map->height = extract_attribute(map_tag, "height");

    if (map->width <= 0 || map->height <= 0) {
        return -1;
    }
    return 0;
}

int load_tileset_texture(map_t *map)
{
    map->texture = sfTexture_createFromFile("assets/map/tileset.png", NULL);
    if (map->texture == NULL)
        return -1;
    return 0;
}

void free_layer_tiles(layer_t *layer, int rows)
{
    for (int k = 0; k < rows; k++)
        free(layer->tiles[k]);
    free(layer->tiles);
    free(layer);
}

layer_t *create_layer(int width, int height, sfTexture *texture)
{
    layer_t *layer = malloc(sizeof(layer_t));
    if (layer == NULL) {
        return NULL;
    }

    layer->width = width;
    layer->height = height;
    layer->tiles = malloc(height * sizeof(sfSprite **));
    if (layer->tiles == NULL) {
        free(layer);
        return NULL;
    }

    for (int i = 0; i < height; i++) {
        if ((layer->tiles[i] = malloc(width * sizeof(sfSprite *))) == NULL) {
            for (int k = 0; k < i; k++) free(layer->tiles[k]);
            free(layer->tiles);
            free(layer);
            return NULL;
        }
        for (int j = 0; j < width; j++) {
            if ((layer->tiles[i][j] = sfSprite_create()) == NULL) {
                free_layer_tiles(layer, i);
                return NULL;
            }
            sfSprite_setTexture(layer->tiles[i][j], texture, sfTrue);
        }
    }

    return layer;
}

void configure_tile(layer_t *layer, int tile_id, int i, int j, sfTexture *texture)
{
    int tileWidth = 16;
    int tileHeight = 16;

    if (tile_id == 0) {
        sfSprite_setTextureRect(layer->tiles[i][j], (sfIntRect){0, 0, 0, 0});
    } else {
        int x = j * tileWidth;
        int y = i * tileHeight;
        sfSprite_setPosition(layer->tiles[i][j], (sfVector2f){x, y});

        sfVector2u tileset_size = sfTexture_getSize(texture);
        int tilesPerRow = (int)tileset_size.x / tileWidth;

        sfIntRect rect;
        rect.left = ((tile_id - 1) % tilesPerRow) * tileWidth;
        rect.top = ((tile_id - 1) / tilesPerRow) * tileHeight;
        rect.width = tileWidth;
        rect.height = tileHeight;
        sfSprite_setTextureRect(layer->tiles[i][j], rect);
    }
}

int configure_tiles(layer_t *layer, char **tile_data, sfTexture *texture)
{
    int tile_index = 0;
    int tile_id = 0;

    for (int i = 0; i < layer->height; i++) {
        for (int j = 0; j < layer->width; j++) {
             tile_id = (int)strtol(tile_data[tile_index], NULL, 10);
             tile_index++;
            configure_tile(layer, tile_id, i, j, texture);
        }
    }
    return 0;
}

int add_layer(map_t *map, char *layer_tag)
{
    map->layer_count++;
    layer_t **temp = realloc(map->layers, map->layer_count * sizeof(layer_t *));
    if (temp == NULL)
        return -1;
    map->layers = temp;

    layer_t *layer = create_layer(map->width, map->height, map->texture);
    if (layer == NULL) {
        return -1;
    }
    map->layers[map->layer_count - 1] = layer;

    char *data_buffer = extract_data_section(layer_tag);
    if (data_buffer == NULL)
        return -1;
    char **tile_data = my_str_to_word_array(data_buffer, ",");
    free(data_buffer);
    if (tile_data == NULL)
        return -1;

    int result = configure_tiles(layer, tile_data, map->texture);

    for (int i = 0; tile_data[i] != NULL; i++) {
        free(tile_data[i]);
    }
    free(tile_data);

    return result;
}

map_t *parse_map_data(char *raw_map_data)
{
    map_t *map = allocate_map();
    if (map == NULL) {
        return NULL;
    }

    char *map_tag = find_tag(raw_map_data, "<map");
    if (map_tag == NULL || extract_map_dimensions(map, map_tag) < 0 ||
        load_tileset_texture(map) < 0) {
        free(map);
        return NULL;
    }

    char *layer_tag = raw_map_data;
    while ((layer_tag = find_tag(layer_tag, "<layer")) != NULL) {
        if (add_layer(map, layer_tag) < 0) {
            free_map(map);
            return NULL;
        }
        layer_tag = strstr(layer_tag, "</layer>");
    }
    return map;
}
