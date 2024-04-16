/*
** EPITECH PROJECT, 2023
** my_strcapitalize
** File description:
** a function that capitalizes the first letter of each word.
*/

static int is_upper_letter(char c)
{
    return (c >= 'A' && c <= 'Z');
}

static int is_dwn_letter(char c)
{
    return (c >= 'a' && c <= 'z');
}

static int is_number(char c)
{
    return (c >= '0' && c <= '9');
}

static int is_alpha(char c)
{
    return (is_upper_letter(c) || is_number(c) || is_dwn_letter(c));
}

char *my_strcapitalize(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (is_dwn_letter(str[i]) && ((i == 0) || !is_alpha(str[i - 1]))) {
            str[i] -= 32;
        }
        if (is_upper_letter(str[i]) && is_alpha(str[i - 1])) {
            str[i] += 32;
        }
        i++;
    }
    return str;
}
