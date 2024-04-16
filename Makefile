##
## EPITECH PROJECT, 2023
## B-MUL-100-LIL-1-1-myrpg-raphael.richaud
## File description:
## Makefile
##

CC = gcc
CFLAGS = -Wall -Wextra -g #-Werror
LFLAGS = -Llib/ -lmy
CSFMLFLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-audio -lcsfml-system
SRC = main.c
OBJS = $(SRC:.c=.o)
NAME = my_rpg

all: $(NAME)

$(NAME): $(OBJS)
	make -C lib/
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LFLAGS) $(CSFMLFLAGS)

clean:
	make clean -C lib/
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all
