/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** loader_core.c
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "rpg.h"

static char *load_map_from_disk(const char *path)
{
    FILE *map_file = fopen(path, "r");
    struct stat st;
    char *buffer = NULL;

    if (map_file == NULL) {
        perror("Error opening map file");
        return NULL;
    }
    if (stat(path, &st) == -1) {
        perror("Error getting file stats");
        fclose(map_file);
        return NULL;
    }
    buffer = malloc(st.st_size + 1);
    if (buffer == NULL) {
        perror("Error allocating memory for buffer");
        fclose(map_file);
        return NULL;
    }
    if (fread(buffer, st.st_size, 1, map_file) != 1) {
        perror("Error reading file");
        free(buffer);
        fclose(map_file);
        return NULL;
    }
    buffer[st.st_size] = '\0';
    fclose(map_file);
    return buffer;
}

// Fonction utilitaire pour trouver une balise dans le XML
char *find_tag(char *data, const char *tag) {
    char *start = strstr(data, tag);
    if (start == NULL) return NULL;
    return start;
}

// Fonction utilitaire pour extraire un attribut d'une balise XML
int extract_attribute(char *tag, const char *attribute) {
    char *attr_pos = strstr(tag, attribute);
    if (attr_pos == NULL) return -1;
    char *value_start = strchr(attr_pos, '"');
    if (value_start == NULL) return -1;
    char *value_end = strchr(value_start + 1, '"');
    if (value_end == NULL) return -1;

    char buffer[16];
    strncpy(buffer, value_start + 1, value_end - value_start - 1);
    buffer[value_end - value_start - 1] = '\0';

    return atoi(buffer);
}

// Fonction pour analyser les données brutes de la carte
map_t *parse_map_data(char *raw_map_data) {
    map_t *map = malloc(sizeof(map_t));
    if (map == NULL)
        return NULL;

    // Trouver la balise <map>
    char *map_tag = find_tag(raw_map_data, "<map");
    if (map_tag == NULL) {
        free(map);
        return NULL;
    }

    // Extraire les dimensions de la carte
    map->width = extract_attribute(map_tag, "width");
    map->height = extract_attribute(map_tag, "height");
    printf("Map dimensions: %d x %d\n", map->width, map->height);

    if (map->width <= 0 || map->height <= 0) {
        free(map);
        return NULL;
    }

    // Charger la texture des tuiles
    map->texture = sfTexture_createFromFile("assets/map/tileset.png", NULL);
    if (map->texture == NULL) {
        free(map);
        return NULL;
    }

    // Initialiser les calques
    map->layer_count = 0;
    map->layers = NULL;

    char *layer_tag = raw_map_data;
    while ((layer_tag = find_tag(layer_tag, "<layer")) != NULL) {
        map->layer_count++;
        layer_t **temp = realloc(map->layers, map->layer_count * sizeof(layer_t *));
        if (temp == NULL) {
            free(map->layers);
            sfTexture_destroy(map->texture);
            free_map(map);
            return NULL;
        }
        map->layers = temp;

        layer_t *layer = malloc(sizeof(layer_t));
        if (layer == NULL) {
            sfTexture_destroy(map->texture);
            free_map(map);
            return NULL;
        }
        map->layers[map->layer_count - 1] = layer;

        layer->width = map->width;
        layer->height = map->height;
        layer->tiles = malloc(map->height * sizeof(sfSprite **));
        if (layer->tiles == NULL) {
            free(layer);
            sfTexture_destroy(map->texture);
            free_map(map);
            return NULL;
        }
        for (int i = 0; i < map->height; i++) {
            layer->tiles[i] = malloc(map->width * sizeof(sfSprite *));
            if (layer->tiles[i] == NULL) {
                for (int k = 0; k < i; k++)
                    free(layer->tiles[k]);
                free(layer->tiles);
                free(layer);
                sfTexture_destroy(map->texture);
                free_map(map);
                return NULL;
            }
            for (int j = 0; j < map->width; j++) {
                layer->tiles[i][j] = sfSprite_create();
                if (layer->tiles[i][j] == NULL) {
                    for (int k = 0; k <= i; k++)
                        free(layer->tiles[k]);
                    free(layer->tiles);
                    free(layer);
                    sfTexture_destroy(map->texture);
                    free_map(map);
                    return NULL;
                }
                sfSprite_setTexture(layer->tiles[i][j], map->texture, sfTrue);
            }
        }

        // Trouver la balise <data>
        char *data_tag = find_tag(layer_tag, "<data");
        if (data_tag == NULL) {
            sfTexture_destroy(map->texture);
            free_map(map);
            return NULL;
        }

        // Trouver la pos de début des données (après la balise <data>)
        char *data_start = strchr(data_tag, '>');
        if (data_start == NULL) {
            sfTexture_destroy(map->texture);
            free_map(map);
            return NULL;
        }
        data_start++; // Passer le '>'

        // Copier les données dans un buffer séparé pour les manipuler
        char *data_end = strstr(data_start, "</data>");
        if (data_end == NULL) {
            sfTexture_destroy(map->texture);
            free_map(map);
            return NULL;
        }

        // Taille des données
        size_t data_length = data_end - data_start;

        // Copier les données dans un buffer temporaire
        char *data_buffer = malloc(data_length + 1);
        if (data_buffer == NULL) {
            sfTexture_destroy(map->texture);
            free_map(map);
            return NULL;
        }
        strncpy(data_buffer, data_start, data_length);
        data_buffer[data_length] = '\0';

        // Analyse des données de tuiles en utilisant my_str_to_word_array
        char **tile_data = my_str_to_word_array(data_buffer, ",");
        if (tile_data == NULL) {
            free(data_buffer);
            sfTexture_destroy(map->texture);
            free_map(map);
            return NULL;
        }

        sfVector2u tileset_size = sfTexture_getSize(map->texture);
        int tile_index = 0;
        int tileWidth = 16;
        int tileHeight = 16;
        int tilesPerRow = (int)tileset_size.x / tileWidth; // Nombre de tuiles par ligne dans le fichier de texture

        for (int i = 0; i < layer->height; i++) {
            for (int j = 0; j < layer->width; j++) {
                int tile_id = atoi(tile_data[tile_index]);
                if (tile_id == 0) {
                    // Tuile transparente, ne rien faire
                    sfSprite_setTextureRect(layer->tiles[i][j], (sfIntRect){0, 0, 0, 0});
                } else {
                    int x = j * tileWidth;
                    int y = i * tileHeight;
                    sfSprite_setPosition(layer->tiles[i][j], (sfVector2f){x, y});

                    // Calculer l'indice de la tuile dans le fichier de texture
                    sfIntRect rect;
                    rect.left = ((tile_id - 1) % tilesPerRow) * tileWidth;
                    rect.top = ((tile_id - 1) / tilesPerRow) * tileHeight;
                    rect.width = tileWidth;
                    rect.height = tileHeight;
                    sfSprite_setTextureRect(layer->tiles[i][j], rect);
                }
                tile_index++;
            }
        }

        // Libérer la mémoire allouée pour tile_data
        for (int i = 0; tile_data[i] != NULL; i++) {
            free(tile_data[i]);
        }
        free(tile_data);
        free(data_buffer);

        layer_tag = data_end;
    }

    return map;
}

void load_map(rpg_t *main)
{
    map_t *map = NULL;
    char *raw_map_data = load_map_from_disk("assets/map/map.tmx");

    if (raw_map_data == NULL)
        return;
    map = parse_map_data(raw_map_data);
    if (map == NULL) {
        free(raw_map_data);
        return;
    }
    main->map = map;
    free(raw_map_data);
}

void free_map(map_t *map)
{
    if (map) {
        for (int l = 0; l < map->layer_count; l++) {
            for (int i = 0; i < map->layers[l]->height; i++) {
                for (int j = 0; j < map->layers[l]->width; j++)
                    sfSprite_destroy(map->layers[l]->tiles[i][j]);
                free(map->layers[l]->tiles[i]);
            }
            free(map->layers[l]->tiles);
            free(map->layers[l]);
        }
        free(map->layers);
        sfTexture_destroy(map->texture);
        free(map);
    }
}

void draw_map(rpg_t *main, map_t *map)
{
    entity_t *player = find_entity(main, "player");
    sfVector2f center = {player->pos.x, player->pos.y};
    sfVector2f size = {main->window->mode.width / 3, main->window->mode.height / 3};
    sfView_setCenter(main->view, center);
    sfView_setSize(main->view, size);
    sfRenderWindow_setView(main->window->window, main->view);

    for (int l = 0; l < map->layer_count; l++) {
        for (int i = 0; i < map->layers[l]->height; i++) {
            for (int j = 0; j < map->layers[l]->width; j++)
                sfRenderWindow_drawSprite(main->window->window, map->layers[l]->tiles[i][j], NULL);
        }
    }
}