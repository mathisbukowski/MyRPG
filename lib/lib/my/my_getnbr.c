/*
** EPITECH PROJECT, 2023
** my_getnbr
** File description:
** a function that returns a number,
** sent to the function as a string.
*/

static int check_num(const char *str, int index, int result, int sign)
{
    int digit;

    while (str[index] >= '0' && str[index] <= '9') {
        digit = str[index] - '0';
        if (result > 214748364) {
            return 0;
        }
        if (result == 214748364 && digit > 7 && sign == 1) {
            return 0;
        }
        if (result == 214748364 && digit > 8 && sign == -1) {
            return 0;
        }
        result = result * 10 + digit;
        index++;
    }
    return result;
}

int my_getnbr(const char *str)
{
    int sign = 1;
    int result = 0;
    int i = 0;

    while (str[i] == ' ') {
        i++;
    }
    while (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-') {
            sign = -sign;
        }
        i++;
    }
    result = check_num(str, i, result, sign);
    return result * sign;
}
