/*
** EPITECH PROJECT, 2023
** my_strdup
** File description:
** a function that allocates memory and copies the string given
** as argument in it
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(const char *src)
{
    char *str;
    size_t len = my_strlen(src) + 1;

    if (src == NULL)
        return NULL;
    str = malloc((len + 1) * sizeof(char));
    if (str == NULL)
        return NULL;
    for (size_t i = 0; i < len; i++)
        str[i] = src[i];
    str[len] = '\0';
    return str;
}
