/*
** EPITECH PROJECT, 2023
** : my.h
** File description:
** my.h header file that contains the prototypes of all the functions
** exposed by libmy.a
*/

#ifndef MY_H
    #define MY_H

typedef struct indices_s {
    int j;
    int k;
    int i;
} indices_t;

void my_putchar(char c);
int my_isneg(int nb);
void my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
int get_nb_length(int nb);
int power(int nbo, int p);
int my_char_isalpha(char c);
char **my_str_to_word_array(char *str, char *separators);
void free_double_array(char **word_ar);
char *my_strdup(char const *src);
int my_show_double_array(char *const *tab);
void prepare_word_alloc(int *, int *, int *, const char *);
int my_put_errorstr(char const *str);
void int_to_str(int n, char *str);
void float_to_str(double nb, char *str, int precision);
int my_round(double nb);
int is_char_in_arr(char arr[], char ch);
int my_arrlen(char **arr);
int my_clear_str(char *str, int size);

#endif
