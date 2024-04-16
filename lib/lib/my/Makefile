##
## EPITECH PROJECT, 2023
## makefile
## File description:
## makefile to build project
##

SRC 	= my_compute_square_root.c \
	my_isneg.c \
	my_put_nbr.c \
	my_showmem.c \
	my_sort_int_array.c \
	my_strcmp.c \
	my_str_isalpha.c \
	my_str_isprintable.c \
	my_strlowcase.c \
	my_strncpy.c \
	my_strupcase.c \
	my_find_prime_sup.c \
	my_is_prime.c \
	my_putstr.c \
	my_showstr.c \
	my_strcapitalize.c \
	my_strcpy.c \
	my_str_islower.c \
	my_str_isupper.c \
	my_strncat.c \
	my_strstr.c \
	my_swap.c \
	my_compute_power_rec.c \
	my_getnbr.c \
	my_putchar.c \
	my_revstr.c \
	my_show_double_array.c \
	my_strcat.c \
	my_strdup.c \
	my_str_isnum.c \
	my_strlen.c \
	my_strncmp.c \
	my_str_to_word_array.c \
	my_put_errorstr.c \
	my_round.c \
	is_char_in_arr.c \
	my_arrlen.c \
	int_to_str.c \
	my_clear_str.c \
	my_strrchr.c

OBJS    = ${SRC:.c=.o}
CFLAGS  = -Wall -Wextra -Werror -shared
NAME  	= libmy

all: $(NAME)

$(NAME) : $(OBJS)
	gcc -o $(NAME) $(CFLAGS) $(OBJS)
	$(AR) rc ./$(NAME).a $(OBJS)
	cp my.h ../../include/

clean:
	rm -f ${OBJS}

fclean:
	rm -f ${NAME}

re:
	clean
	fclean
