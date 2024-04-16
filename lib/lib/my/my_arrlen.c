/*
** EPITECH PROJECT, 2023
** B-MUL-100-LIL-1-1-myradar-raphael.richaud
** File description:
** my_arrlen.c
*/

#include <stdlib.h>

int my_arrlen(char **arr)
{
    int i = 0;

    while (arr[i] != NULL)
        i++;
    return i;
}
