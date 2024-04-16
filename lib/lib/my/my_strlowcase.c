/*
** EPITECH PROJECT, 2023
** my_strlowcase
** File description:
** a function that puts every letter of every word in it in lowercase.
*/

char *my_strlowcase(char *str)
{
    char *out = str;

    while (*str) {
        if (*str >= 65 && *str <= 90) {
            *str += 32;
        }
        str++;
    }
    return out;
}
