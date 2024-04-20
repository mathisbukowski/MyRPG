##
## EPITECH PROJECT, 2024
## shell1
## File description:
## Makefile for minishell project
##

SRC = src/main.c src/rpg.c src/utils/check_tty.c \
		src/utils/print_help.c src/utils/init_structure.c \
		src/utils/free_project.c \
		src/events/event_manager.c \
		src/window_manager/create_window.c src/window_manager/display_window.c\
		src/window_manager/destroy_window.c

OBJ = $(SRC:.c=.o)

NAME = my_rpg

LIB = -L./lib/my -lmy -lcsfml-graphics -lcsfml-system -lcsfml-window
CFLAGS = -Wall -Wextra  -I./include -g #-Werror

all: $(NAME)

$(NAME): $(OBJ)
	make -C lib/my
	gcc $(CFLAGS) $(OBJ) -o $(NAME) $(LIB)
	make clean -C lib/my

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f vgcore.*
	rm -f $(NAME)

re: fclean all

.PHONY: libmy
libmy:
	make -C lib/my
