/*
** EPITECH PROJECT, 2023
** my_getnbr.c
** File description:
** get number
*/
#include "../../include/my.h"
#include <stdio.h>

int my_getnbr(char const *str)
{
    int index;
    int nb;
    int result;

    if (str == NULL)
        return -1;
    nb = 1;
    result = 0;
    index = my_strlen(str) - 1;
    while (index >= 0) {
        if (str[index] < '0' || str[index] > '9')
            return -1;
        result += (str[index] - 48) * nb;
        nb *= 10;
        index--;
    }
    return result;
}
