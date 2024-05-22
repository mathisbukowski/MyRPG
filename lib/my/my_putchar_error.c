/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** my_putchar_error.cpp
*/

#include <unistd.h>

void my_putchar_error(char c)
{
    write(2, &c, 1);
}
