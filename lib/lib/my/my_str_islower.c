/*
** EPITECH PROJECT, 2023
** my_str_islower
** File description:
** a function that returns 1 if the string passed as parameter only
** contains lowercase alphabetical characters and 0 otherwise.
*/

int my_str_islower(char const *str)
{
    while (*str) {
        if (!(*str >= 97 && *str <= 122)) {
            return 0;
        }
        str++;
    }
    return 1;
}
