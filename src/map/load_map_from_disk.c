/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** load_map_from_disk.c
*/

#include "rpg.h"

static FILE *open_map_file(const char *path)
{
    FILE *map_file = fopen(path, "r");

    if (map_file == NULL)
        perror("Error opening map file");
    return map_file;
}

static int get_file_size(const char *path, struct stat *st)
{
    if (stat(path, st) == -1) {
        perror("Error getting file stats");
        return -1;
    }
    return 0;
}

static char *allocate_buffer(size_t size)
{
    char *buffer = malloc(size + 1);

    if (buffer == NULL)
        perror("Error allocating memory for buffer");
    return buffer;
}

static int read_file_to_buffer(FILE *file, char *buffer, size_t size)
{
    if (fread(buffer, size, 1, file) != 1) {
        perror("Error reading file");
        return -1;
    }
    buffer[size] = '\0';
    return 0;
}

FILE *load_map_file(const char *path, struct stat *st)
{
    FILE *map_file = open_map_file(path);

    if (map_file == NULL)
        return NULL;
    if (get_file_size(path, st) == -1) {
        fclose(map_file);
        return NULL;
    }
    return map_file;
}

char *read_map_data(const char *path, FILE *map_file, size_t size)
{
    char *buffer = allocate_buffer(size);

    if (buffer == NULL) {
        fclose(map_file);
        return NULL;
    }
    if (read_file_to_buffer(map_file, buffer, size) == -1) {
        free(buffer);
        fclose(map_file);
        return NULL;
    }
    fclose(map_file);
    return buffer;
}

char *load_map_from_disk(const char *path)
{
    struct stat st;
    FILE *map_file = load_map_file(path, &st);

    if (map_file == NULL)
        return NULL;
    return read_map_data(path, map_file, st.st_size);
}
