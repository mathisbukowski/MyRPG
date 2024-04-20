/*
** EPITECH PROJECT, 2023
** my_strncmp
** File description:
** my_strncmp
*/
int my_strcmp_char(const char c1, const char c2)
{
    if (c1 < c2) {
        return -1;
    } else if (c1 > c2) {
        return 1;
    }
    return 0;
}

int my_strncmp(const char *s1, const char *s2, int n)
{
    int i;
    int cmp_result_for;
    int cmp_result_if;

    for (i = 0; (s1[i] != '\0' && s2[i] != '\0' && i < n); ++i) {
        cmp_result_for = my_strcmp_char(s1[i], s2[i]);
        if (cmp_result_for != 0) {
            return cmp_result_for;
        }
    }
    if (i < n) {
        cmp_result_if = my_strcmp_char(s1[i], s2[i]);
        if (cmp_result_if != 0) {
            return cmp_result_if;
        }
    }
    return 0;
}
