/*
** EPITECH PROJECT, 2024
** B-PSU-200-LIL-2-1-minishell1-raphael.richaud
** File description:
** get_double_array_len.c
*/

#include <stdlib.h>

int get_double_array_len(char **array)
{
    int i = 0;

    if (array == NULL)
        return 0;
    while (array[i] != 0)
        i++;
    return i;
}
