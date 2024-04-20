##
## EPITECH PROJECT, 2024
## shell1
## File description:
## Makefile for minishell project
##

SRC = src/main.c\


NAME = my_rpg

LIB = -L./lib/my -lmy -lcsfml-graphics -lcsfml-system -lcsfml-window

CFLAGS =  -g

all : $(NAME)

$(NAME) :
	make -C lib/my
	gcc $(CFLAGS) $(SRC) -o $(NAME) $(LIB)
	make clean -C lib/my

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f vgcore.*
	rm -f $(NAME)

re: fclean all
