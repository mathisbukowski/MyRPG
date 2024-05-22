/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** map.h
*/

#ifndef MAP_H
#define MAP_H
#include "rpg.h"

typedef struct property_s property_t;
typedef struct map_s map_t;

typedef struct layer_s {
    sfSprite ***tiles;
    int width;
    int height;
} layer_t;

typedef struct map_s {
    sfTexture *texture;
    layer_t **layers;
    int layer_count;
    int width;
    int height;
} map_t;

void load_map(rpg_t *main);
void draw_map(rpg_t *main, map_t *map);
void free_map(map_t *map);

char *load_map_from_disk(const char *path);
char *find_tag(char *data, const char *tag);
int extract_attribute(char *tag, const char *attribute);
char *extract_data_section(char *layer_tag);
#endif //MAP_H