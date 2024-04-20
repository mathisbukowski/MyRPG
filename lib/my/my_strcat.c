/*
** EPITECH PROJECT, 2023
** my_strcat
** File description:
** my_strcat
*/
#include "../../include/my.h"
#include <stdlib.h>

static char *concat_string_dest(char *result, char *str, int size_dest)
{
    for (int i = 0; i < size_dest; i++)
        result[i] = str[i];
    return result;
}

static char *concat_src(char *result, char const *str,
    int size_dest, int size_src)
{
    for (int i = 0; i < size_src; i++)
        result[i + size_dest + 1] = str[i];
    return result;
}

char *my_strcat(char *dest, char const *src)
{
    int size_dest = 0;
    int size_src = 0;
    char *result;

    if (dest == NULL || src == NULL)
        return NULL;
    size_dest = my_strlen(dest);
    size_src = my_strlen(src);
    result = malloc((size_dest + size_src + 2) * sizeof(char));
    if (result == NULL) {
        return NULL;
    }
    concat_string_dest(result, dest, size_dest);
    result[size_dest] = '/';
    concat_src(result, src, size_dest, size_src);
    result[size_dest + size_src + 1] = '\0';
    return result;
}
