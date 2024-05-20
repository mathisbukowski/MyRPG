/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** free_double_array.c
*/

#include <stdlib.h>

void free_double_array(char **word_ar)
{
    int i = 0;

    if (word_ar == NULL)
        return;
    while (word_ar[i] != NULL) {
        free(word_ar[i]);
        i++;
    }
    free(word_ar);
    word_ar = NULL;
}
