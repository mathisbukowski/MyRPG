/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** loader_core.c
*/

#include <stdlib.h>
#include "rpg.h"
#include <sys/stat.h>

static char *load_map_from_disk(const char *path)
{
    FILE *map_file = fopen(path, "r");
    struct stat st;
    char *buffer = NULL;

    if (map_file == NULL||  stat(path, &st) == -1)
        return NULL;
    buffer = malloc(st.st_size + 1);
    if (buffer == NULL) {
        fclose(map_file);
        return NULL;
    }
    fread(buffer, st.st_size, 1, map_file);
    buffer[st.st_size] = '\0';
    fclose(map_file);
    return buffer;
}

static int handle_map_data(char *map_data, map_t *map)
{
    char **data_lines = my_str_to_word_array(map_data, "\n");

    if (data_lines == NULL)
        return 84;
    for (int i = 0; data_lines[i]; i++) {
        printf("%s\n", data_lines[i]);
    }
    return 0;
}

map_t *load_map(const char *path)
{
    map_t *map = malloc(sizeof(map_t));
    char *map_data = load_map_from_disk(path);

    if (map_data == NULL)
        return NULL;
    if (map == NULL) {
        free(map_data);
        return NULL;
    }
    if (handle_map_data(map_data, map) == 84)
        return NULL;
    free(map_data);
    return map;
}
