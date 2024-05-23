/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** rpg.c
*/

#include "rpg.h"

void screen_manager(rpg_t *main)
{
    add_event_to_list(main, &close_window, sfEvtClosed);
    add_key_to_keymap(&(main->keymap), sfKeyEscape, &close_window);
    add_entity_to_list(main, (entity_params_t){"background",
    (sfVector2f){0, 0}, BACKGROUND}, "assets/bg.jpg");
    add_entity_to_list(main, (entity_params_t){"player",
    (sfVector2f){900, 508}, PLAYER}, "assets/player/player.png");
    add_entity_to_list(main, (entity_params_t){"npc",
    (sfVector2f){800, 508}, NPC}, "assets/player/npc.png");
    init_start_scene(main);
    init_params_scene(main);
    init_game_scene(main);
    init_player_sprite(main);
    while (sfRenderWindow_isOpen(main->window->renderWindow)) {
        event_manager(main);
        update_view(main);
        display_window(main);
    }
}

int game_logic(int ac, char **av)
{
    rpg_t *main = init_structure();

    if (av[1] != NULL)
        loading_system(main, av);
    create_window(1920, 1080, "RPGLand", main);
    load_map(main);
    if (main->map == NULL) {
        my_putstr("Error: Map not loaded\n");
        return 84;
    }
    screen_manager(main);
    destroy_window(main);
    free_rpg(main);
    return 0;
}
