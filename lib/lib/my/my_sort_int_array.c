/*
** EPITECH PROJECT, 2023
** my_sort_int_array
** File description:
** a function that sorts an integer array in ascending order,
** given a pointer to the first element of the array and its size.
*/

#include "my.h"

static void check_int(int int_j, int int_min, int j, int *min)
{
    if (int_j < int_min) {
        *min = j;
    }
}

void my_sort_int_array(int *array, int size)
{
    int min;

    for (int i = 0; i < size - 1; i++) {
        min = i;
        for (int j = i + 1; j < size; j++) {
            check_int(array[j], array[min], j, &min);
        }
        my_swap(&array[min], &array[i]);
    }
}
