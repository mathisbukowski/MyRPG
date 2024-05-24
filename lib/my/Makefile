##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile for my lib
##
SRC = d_i_s_c_o_flags.c \
        flag_e.c\
        flag_e_maj.c\
        flag_g.c\
        my_compute_power_rec.c\
        my_compute_square_root.c\
        my_find_prime_sup.c\
        my_getnbr.c\
        my_isneg.c \
        my_is_prime.c\
        my_printf.c\
        my_putchar.c\
        my_put_nbr.c\
        my_put_nbr_f_flag.c\
        my_putstr.c\
        my_revstr.c\
        my_showmem.c\
        my_showstr.c\
        my_sort_int_array.c\
        my_strcapitalize.c\
        my_strcat.c\
        my_strcmp.c\
        my_strcpy.c\
        my_strdup.c\
        my_str_isalpha.c\
        my_str_islower.c\
        my_str_isnum.c\
        my_str_isprintable.c\
        my_str_isupper.c\
        my_strlen.c\
        my_strlowcase.c\
        my_strncat.c\
        my_strncmp.c\
        my_strncpy.c\
        my_strstr.c\
        my_str_to_word_array.c\
        my_strupcase.c\
        my_swap.c\
        n_p_modulo_flags.c\
        x_u_f_flags.c\
        my_atoi.c\
        my_memcpy.c\
        my_realloc.c\
        my_putstr_error.c\
        my_putchar_error.c\
        my_strchr.c\
        my_strrchr.c\
        my_show_double_array.c\
        free_double_array.c\
        get_double_array_len.c\

OBJ = $(SRC:.c=.o)
LIB = libmy.a

CFLAGS = -Wall -Wextra  -I./include -g #-Werror

all: $(LIB)

$(LIB): $(OBJ)
	ar rcs $@ $^

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(LIB)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
