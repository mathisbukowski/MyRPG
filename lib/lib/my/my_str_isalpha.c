/*
** EPITECH PROJECT, 2023
** my_isalpha
** File description:
** Write a function that returns 1 if the string passed as parameter
** only contains alphabetical characters and 0 if the string contains
** another type of character.
*/

static int is_u_l(char c)
{
    return (c >= 'A' && c <= 'Z');
}

static int is_d_l(char c)
{
    return (c >= 'a' && c <= 'z');
}

static int is_num(char c)
{
    return (c >= '0' && c <= '9');
}

int my_str_isalpha(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (!(is_u_l(str[i]) && is_num(str[i]) && is_d_l(str[i]))) {
            return 0;
        }
        str++;
    }
    return 1;
}
