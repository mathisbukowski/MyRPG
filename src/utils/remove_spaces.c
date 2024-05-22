/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** remove_spaces.c
*/

#include <stdlib.h>
#include <string.h>

char *remove_spaces(char *str)
{
    int i = 0;
    int j = 0;
    int len = strlen(str);
    char *new_str = malloc(len + 1);

    if (!new_str)
        return NULL;
    for (i = 0; i < len; i++)
        if (str[i] != ' ') {
            new_str[j] = str[i];
            j++;
        }
    new_str[j] = '\0';
    return new_str;
}
