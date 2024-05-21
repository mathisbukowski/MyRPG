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

#endif //MAP_H