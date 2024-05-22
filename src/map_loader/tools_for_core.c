/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** tools_for_core.c
*/

#include "rpg.h"

char *find_tag(char *data, const char *tag)
{
    char *start = strstr(data, tag);

    if (start == NULL) return NULL;
    return start;
}

int extract_attribute(char *tag, const char *attribute)
{
    char *attr_pos;
    char *value_start;
    char *value_end;
    char buffer[16];

    attr_pos = strstr(tag, attribute);
    if (attr_pos == NULL)
        return -1;
    value_start = strchr(attr_pos, '"');
    if (value_start == NULL)
        return -1;
    value_end = strchr(value_start + 1, '"');
    if (value_end == NULL)
        return -1;
    strncpy(buffer, value_start + 1, value_end - value_start - 1);
    buffer[value_end - value_start - 1] = '\0';
    return atoi(buffer);
}
