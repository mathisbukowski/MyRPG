/*
** EPITECH PROJECT, 2023
** my_strncmp
** File description:
** compares two strings character by character. If the strings are equal,
** the function returns 0.
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    for (int i = 0; i < n; i++) {
        if (s1[i] == '\0' || s2[i] == '\0')
            return s1[i] - s2[i];
        if (s1[i] - s2[i] != 0)
            return s1[i] - s2[i];
    }
    return 0;
}
