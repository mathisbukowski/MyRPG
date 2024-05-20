/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-mypaint-mathis.bukowski
** File description:
** my_strchr.cc
*/

#include <unistd.h>

char *my_strchr(char const *str, int index)
{
    unsigned char uc;

    if (str == NULL)
        return NULL;
    uc = (unsigned char)index;
    while (*str != '\0') {
        if (*str == uc)
            return (char *)str;
        str++;
    }
    if (uc == '\0')
        return (char *)str;
    return NULL;
}
