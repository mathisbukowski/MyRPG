/*
** EPITECH PROJECT, 2024
** B-PSU-200-LIL-2-1-minishell1-raphael.richaud
** File description:
** my_clear_str.c
*/

int my_clear_str(char *str, int size)
{
    for (int i = 0; i < size; i++)
        str[i] = '\0';
    return 0;
}
