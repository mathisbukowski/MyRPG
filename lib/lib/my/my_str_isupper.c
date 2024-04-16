/*
** EPITECH PROJECT, 2023
** my_str_isupper
** File description:
** a function that returns 1 if the string passed as parameter only
** contains uppercase alphabetical characters and 0 otherwise.
*/

int my_str_isupper(char const *str)
{
    while (*str) {
        if (!(*str >= 65 && *str <= 90)) {
            return 0;
        }
        str++;
    }
    return 1;
}
