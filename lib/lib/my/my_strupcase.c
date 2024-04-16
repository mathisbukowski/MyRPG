/*
** EPITECH PROJECT, 2023
** my_strupcase
** File description:
** a function that puts every letter of every word in it in uppercase.
*/

char *my_strupcase(char *str)
{
    char *out = str;

    while (*str) {
        if (*str >= 97 && *str <= 122) {
            *str -= 32;
        }
        str++;
    }
    return out;
}
