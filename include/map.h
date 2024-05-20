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

typedef struct layer_s {
    int id;
    char *name;
    int width;
    int height;
    int **tiles;
}layer_t;

typedef struct map_s {
    layer_t *layers_list;
}map_t;

map_t *load_map(const char *path);
#endif //MAP_H
