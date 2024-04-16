/*
** EPITECH PROJECT, 2024
** B-PSU-200-LIL-2-1-minishell2-raphael.richaud
** File description:
** my_strrchr.c
*/

#include <stdlib.h>

char *my_strrchr(const char *str, int ch)
{
    char *lastOccurrence = NULL;
    char chr = (char)ch;

    while (*str) {
        if (*str == chr)
            lastOccurrence = (char *)str;
        str++;
    }
    if (chr == '\0')
        return (char *)str;
    return lastOccurrence;
}
