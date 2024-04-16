/*
** EPITECH PROJECT, 2023
** B-CPE-110-LIL-1-1-settingup-raphael.richaud
** File description:
** is_char_in_arr.c
*/

#include "my.h"

int is_char_in_arr(char *arr, char ch)
{
    int found = 0;

    for (int i = 0; i < my_strlen(arr); ++i) {
        if (arr[i] == ch) {
            found = 1;
            break;
        }
    }
    return found;
}
