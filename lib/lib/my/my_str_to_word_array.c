/*
** EPITECH PROJECT, 2023
** my_str_to_word_array
** File description:
** a function that splits a string into words. Separators will all be
** non-alphanumeric characters. The function returns an array in which
** each cell contains the address of a string (representing a word).
** The last cell must be null to terminate the array.
*/

#include <stdlib.h>
#include "my.h"

int my_char_isalpha(char c)
{
    int is_lower = c >= 'a' && c <= 'z';
    int is_upper = c >= 'A' && c <= 'Z';
    int is_num = c >= '0' && c <= '9';

    return is_lower || is_upper || is_num;
}

static char *my_strchr(char *str, char c)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == c)
            return &str[i];
    return NULL;
}

void handle_separator(char **words, indices_t *indices, char *str,
    char *separators)
{
    if (indices->k != 0) {
        words[indices->j][indices->k] = '\0';
        indices->j++;
        indices->k = 0;
        words[indices->j] = malloc((my_strlen(str) + 1) * sizeof(char));
    }
    while (str[indices->i + 1] != '\0' && my_strchr(separators,
                                            str[indices->i + 1]) != NULL)
        indices->i++;
}

void handle_non_separator(char **words, int j, int *k, char c)
{
    words[j][*k] = c;
    (*k)++;
}

static void check_and_shift_string(char *str, int i)
{
    if (str[i] == '\\' && str[i + 1] == 'n') {
        str[i] = '\n';
        for (int j = i + 1; str[j] != '\0'; j++)
            str[j] = str[j + 1];
    }
}

static void format_line_jumps(char *str)
{
    if (my_strstr(str, "\\n") != NULL)
        for (int i = 0; str[i] != '\0'; i++)
            check_and_shift_string(str, i);
}

static int is_only_separators(char *str, char *separators)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (my_strchr(separators, str[i]) == NULL)
            return 0;
    return 1;
}

char **my_str_to_word_array(char *str, char *separators)
{
    indices_t indices = {0, 0, 0};
    char **words = malloc((my_strlen(str) + 1) * sizeof(char *));

    if (str != NULL || is_only_separators(str, separators) != 1) {
        words[0] = malloc((my_strlen(str) + 1) * sizeof(char));
        format_line_jumps(str);
    }
    for (indices.i = 0; str[indices.i] != '\0'; indices.i++) {
        if (my_strchr(separators, str[indices.i]) != NULL)
            handle_separator(words, &indices, str, separators);
        else
            handle_non_separator(words, indices.j, &indices.k, str[indices.i]);
    }
    if (indices.k != 0) {
        words[indices.j][indices.k] = '\0';
        indices.j++;
    }
    words[indices.j] = NULL;
    return words;
}

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
