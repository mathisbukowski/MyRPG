/*
** EPITECH PROJECT, 2023
** my_strncpy
** File description:
** a function that copies n characters from a string into another.
** The destination string will already have enough memory to
** contain n characters.
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (i < n && src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    if (n > i) {
        dest[i] = '\0';
    }
    return dest;
}
