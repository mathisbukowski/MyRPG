/*
** EPITECH PROJECT, 2023
** my_strcat
** File description:
** a function that concatenates two strings.
*/

char *my_strcat(char *dest, char const *src)
{
    char *out = dest;

    while (*dest) {
        dest++;
    }
    while (*src) {
        *dest = *src;
        src++;
        dest++;
    }
    *dest = '\0';
    return out;
}

char *my_charadd(char *dest, char const src)
{
    char *out = dest;

    while (*dest) {
        dest++;
    }
    *dest = src;
    dest++;
    *dest = '\0';
    return out;
}
