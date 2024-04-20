/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-mypaint-mathis.bukowski
** File description:
** my_strrchr.c
*/

#include "../../include/my.h"

char *my_strrchr(char const *str, int index)
{
    const char *last_occurrence = NULL;

    index = (unsigned char)index;
    while (*str) {
        if (*str == index)
            last_occurrence = str;
        str++;
    }
    if (index == '\0')
        return (char *)str;
    return (char *)last_occurrence;
}
