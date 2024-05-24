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

enum map_type {
    RENDER_MAP,
    COLLISIONS_MAP
};

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

typedef struct tile_config_s {
    layer_t *layer;
    int tile_id;
    int i;
    int j;
    sfTexture *texture;
} tile_config_t;

void load_map(rpg_t *main, char *map_path, int map_type);
void draw_map(rpg_t *main, map_t *map);

void free_map(map_t *map);
char *load_map_from_disk(const char *path);
char *find_tag(char *data, const char *tag);
int extract_attribute(char *tag, const char *attribute);
char *extract_data_section(char *layer_tag);
map_t *parse_map_data(char *raw_map_data);
void free_layer_tiles(layer_t *layer, int rows);
int extract_map_dimensions(map_t *map, char *map_tag);
int load_tileset_texture(map_t *map);
map_t *allocate_map(void);
layer_t *create_layer(int width, int height, sfTexture *texture);
void configure_tile(tile_config_t *config);
int configure_tiles(layer_t *layer, char **tile_data, sfTexture *texture);
int add_layer(map_t *map, char *layer_tag);
#endif //MAP_H
