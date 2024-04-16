/*
** EPITECH PROJECT, 2023
** my_strlen
** File description:
** a function that counts and returns the number of characters
** found in the string passed as parameter.
*/

int my_strlen(char const *str)
{
    int i = 0;
    int out = 0;

    while (str[i] != '\0') {
        out++;
        i++;
    }
    return out;
}
