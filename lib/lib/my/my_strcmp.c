/*
** EPITECH PROJECT, 2023
** my_strcmp
** File description:
** compares two strings character by character. If the strings are equal,
** the function returns 0.
*/

int my_strcmp(char const *str1, char const *str2)
{
    int i = 0;
    int j = 0;

    while (str1[i] == str2[j] && str1[i] != '\0') {
        i++;
        j++;
    }
    return str1[i] - str2[j];
}
