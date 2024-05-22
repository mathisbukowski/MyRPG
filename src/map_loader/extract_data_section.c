/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** extract_data_section.c
*/

#include "rpg.h"

char *copy_data_section(char const *start, char const *end)
{
    size_t length = end - start;
    char *buffer = malloc(length + 1);

    if (buffer) {
        strncpy(buffer, start, length);
        buffer[length] = '\0';
    }
    return buffer;
}

char *extract_data_section(char *layer_tag)
{
    char *data_tag;
    char *data_start;
    char *data_end;

    data_tag = find_tag(layer_tag, "<data");
    if (data_tag == NULL)
        return NULL;
    data_start = strchr(data_tag, '>');
    if (data_start == NULL)
        return NULL;
    data_start++;
    data_end = strstr(data_start, "</data>");
    if (data_end == NULL)
        return NULL;
    return copy_data_section(data_start, data_end);
}