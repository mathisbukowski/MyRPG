##
## EPITECH PROJECT, 2024
## shell1
## File description:
## Makefile for minishell project
##

SRC = 	src/main.c src/rpg.c 				\
 	  	src/utils/check_tty.c 				\
		src/utils/print_help.c 				\
		src/utils/init_structure.c 			\
		src/utils/free_project.c 			\
		src/utils/check_texture.c 			\
		src/events/event_manager.c 			\
		src/events/init_event.c 			\
		src/events/execute_event.c 			\
		src/events/create_keymap.c 			\
		src/window_manager/create_window.c 	\
		src/window_manager/display_window.c	\
		src/window_manager/destroy_window.c \
		src/entities/create_entity.c 		\
		src/entities/delete_entity.c 		\
		src/entities/display_entity.c 		\
		src/menus/menu.c 					\
		src/menus/sort_menus.c 				\
		src/buttons/buttons.c 				\
		src/buttons/buttons_creator.c 		\
		src/hud_renderer.c 					\
		 src/hud/start_menu.c 				\
		src/init/init_quest.c 				\
		src/init/init_entities.c 			\
		src/init/init_tools.c 				\
		src/scene/adding_scene.c 			\
		src/scene/destroying_scene.c 		\
		src/utils/saving_system.c    		\

OBJ = $(SRC:.c=.o)

NAME = my_rpg

LIB = -L./lib/my -lmy -lcsfml-graphics -lcsfml-system -lcsfml-window
CFLAGS = -Wall -Wextra -I./include -g #-Werror

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
