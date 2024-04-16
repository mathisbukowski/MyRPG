/*
** EPITECH PROJECT, 2023
** my_strncat
** File description:
** a function that concatenates n characters of the src
** string to the end of the dest string.
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    char *out = dest;

    while (*dest) {
        dest++;
    }
    while (*src && nb > 0) {
        *dest = *src;
        dest++;
        src++;
        nb--;
    }
    *dest = '\0';
    return out;
}
