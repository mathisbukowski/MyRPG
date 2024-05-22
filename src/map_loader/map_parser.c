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

    if (!map)
        return NULL;
    map->layer_count = 0;
    map->layers = NULL;
    return map;
}

static char *find_map_tag(char *raw_map_data)
{
    return find_tag(raw_map_data, "<map");
}

static char *find_layer_start(char *raw_map_data)
{
    return find_tag(raw_map_data, "<layer");
}

static char *find_next_layer_end(char *layer_tag)
{
    return strstr(layer_tag, "</layer>");
}

static int parse_map_metadata(map_t *map, char *raw_map_data)
{
    char *map_tag = find_map_tag(raw_map_data);

    if (!map_tag || extract_map_dimensions(map, map_tag) < 0 ||
        load_tileset_texture(map) < 0) {
        return 0;
    }
    return 1;
}

static int parse_map_layers(map_t *map, char *raw_map_data)
{
    char *layer_start = find_layer_start(raw_map_data);
    char *layer_end;

    while (layer_start) {
        layer_end = find_next_layer_end(layer_start);
        if (!layer_end)
            break;
        if (add_layer(map, layer_start) < 0)
            return 0;
        layer_start = find_layer_start(layer_end);
    }
    return 1;
}

map_t *parse_map_data(char *raw_map_data)
{
    map_t *map = allocate_map();

    if (!map)
        return NULL;
    if (!parse_map_metadata(map, raw_map_data)) {
        free(map);
        return NULL;
    }
    if (!parse_map_layers(map, raw_map_data)) {
        free_map(map);
        return NULL;
    }
    return map;
}
