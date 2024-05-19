/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** rpg.c
*/

#include "rpg.h"


void screen_manager(rpg_t *main)
{
    sfFont *font = sfFont_createFromFile("assets/font/font.ttf");

    add_event_to_list(main, &close_window, sfEvtClosed);
    add_key_to_keymap(&(main->keymap), sfKeyEscape, &close_window);
    add_entity_to_list(main, (entity_params_t){"background",
    (sfVector2f){0, 0}, BACKGROUND}, "assets/bg.jpg");
    define_main_menu(main, font);
    while (sfRenderWindow_isOpen(main->window->window)) {
        event_manager(main);
        display_window(main);
    }
}

int game_loop(int ac, char **av)
{
    rpg_t *main = init_structure();

    create_window(1920, 1080, "RPGLand", main);
    screen_manager(main);
    destroy_window(main);
    free_rpg(main);
    return 0;
}
