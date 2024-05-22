/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** my_memcpy.c
*/

#include <stdlib.h>

void *my_memcpy(void *dest, void const *src, size_t len)
{
    unsigned char *destination;
    unsigned const char *source;

    if (dest == NULL || src == NULL)
        return NULL;
    if (len == 0)
        return dest;
    destination = dest;
    source = src;
    if (destination > source && destination < source + len)
        return NULL;
    for (size_t i = 0; i < len; i++)
        destination[i] = source[i];
    return dest;
}
