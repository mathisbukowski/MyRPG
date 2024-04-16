/*
** EPITECH PROJECT, 2023
** my_str_isprintable
** File description:
** a function that returns 1 if the string passed as parameter only
** contains printable characters and 0 otherwise.
*/

int my_str_isprintable(char const *str)
{
    while (*str) {
        if (!(*str >= 32 && *str <= 126)) {
            return 0;
        }
        str++;
    }
    return 1;
}
