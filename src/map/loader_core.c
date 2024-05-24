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
