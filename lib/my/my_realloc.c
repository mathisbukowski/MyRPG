/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** my_realloc.c
*/

#include <stdlib.h>
#include "../../include/my.h"

void *my_realloc(void *ptr, size_t size, size_t old_size)
{
    void *new_ptr = NULL;
    size_t copy_size = 0;

    if (size == 0) {
        free(ptr);
        return NULL;
    }
    if (ptr == NULL)
        return malloc(size);
    new_ptr = malloc(size);
    if (new_ptr == NULL)
        return NULL;
    copy_size = (size < old_size) ? size : old_size;
    my_memcpy(new_ptr, ptr, copy_size);
    free(ptr);
    return new_ptr;
}
