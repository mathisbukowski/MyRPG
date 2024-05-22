/*
** EPITECH PROJECT, 2023
** my_show_word_array
** File description:
**  a function that displays the content of an array of words
*/

#include "../../include/my.h"

int show_double_array(char *const *tab)
{
    for (int i = 0; tab[i] != 0; i++) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
    return 0;
}
