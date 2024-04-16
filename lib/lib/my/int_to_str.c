/*
** EPITECH PROJECT, 2023
** int_to_str
** File description:
** a function that takes as parameters a char* with an int and convert the int
** into the char*
*/

#include "my.h"

static void reverse_print(int i, char *str)
{
    int start = 0;
    char temp;

    while (start < i - 1) {
        temp = str[start];
        str[start] = str[i - 1];
        str[i - 1] = temp;
        start++;
        i--;
    }
}

void put_special(void)
{
    my_putchar('-');
    my_put_nbr(214748364);
    my_putchar('8');
}

void int_to_str(int nb, char *str)
{
    int i = 0;
    int sign = nb;

    if (nb == -2147483648) {
        put_special();
        return;
    }
    if (sign < 0)
        nb = -nb;
    while (nb > 0) {
        i++;
        str[i] = nb % 10 + 48;
        nb /= 10;
    }
    if (sign < 0) {
        i++;
        str[i] = '-';
    }
    str[i] = '\0';
    reverse_print(i, str);
}
