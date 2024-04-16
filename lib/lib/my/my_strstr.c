/*
** EPITECH PROJECT, 2023
** my_strstr
** File description:
** a function that finds the first occurrence of the substring
** in the string used as parameter.
** The terminating '\0' characters are not compared.
*/

char *my_strstr(char *str, const char *to_find)
{
    char *s = str;
    const char *tf = to_find;
    char *temp;

    if (*tf == '\0') {
        return str;
    }
    while (*s != '\0') {
        temp = s;
        while (*temp != '\0' && *tf != '\0' && *temp == *tf) {
            temp++;
            tf++;
        }
        if (*tf == '\0') {
            return s;
        }
        s++;
        tf = to_find;
    }
    return 0;
}
