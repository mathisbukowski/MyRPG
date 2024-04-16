/*
** EPITECH PROJECT, 2023
** my_str_isnum
** File description:
** a function that returns 1 if the string passed as parameter
** only contains digits and 0 otherwise.
*/

int my_str_isnum(char const *str)
{
    while (*str) {
        if (!(*str >= 48 && *str <= 57)) {
            return 0;
        }
        str++;
    }
    return 1;
}
