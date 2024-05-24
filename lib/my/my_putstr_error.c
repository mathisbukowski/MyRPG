/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** my_putstr_error.c
*/

#include "../../include/my.h"

int err_str(char *str)
{
    if (str == NULL)
        return 1;
    for (int i = 0; str[i]; i++)
        my_putchar_error(str[i]);
    return 0;
}
