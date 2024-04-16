/*
** EPITECH PROJECT, 2023
** my_revstr
** File description:
** a function that reverses a string.
*/

#include "my.h"

char *my_revstr(char *str)
{
    int str_len = my_strlen(str);
    char temp;
    int i = str_len - 1;
    int j = 0;

    while (j < i) {
        temp = str[j];
        str[j] = str[i];
        str[i] = temp;
        i--;
        j++;
    }
    return str;
}
