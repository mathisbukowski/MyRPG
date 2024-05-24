/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** rpg.c
*/

#include "rpg.h"

void define_background(rpg_t *main)
{
    main->background_texture = sfTexture_createFromFile("assets/bg.jpg", NULL);
    main->background_sprite = sfSprite_create();
    if (check_texture(main->background_sprite, main->background_texture) != 0)
        return;
}

void screen_manager(rpg_t *main)
{
    entity_t *player;

    add_event_to_list(main, &close_window, sfEvtClosed);
    add_key_to_keymap(&(main->keymap), sfKeyEscape, &open_params);
    add_entity_to_list(main, (entity_params_t){"player",
    (sfVector2f){928, 508}, PLAYER}, "assets/player/player.png");
    define_background(main);
    init_start_scene(main);
    init_params_scene(main);
    init_game_scene(main);
    init_player_sprite(main);
    player = find_entity(main, "player");
    while (sfRenderWindow_isOpen(main->window->render_window)) {
        event_manager(main);
        set_view(main, player);
        display_window(main);
    }
}

int game_logic(int ac, char **av)
{
    rpg_t *main = init_structure();

    if (av[1] != NULL)
        loading_system(main, av);
    create_window(1920, 1080, "RPGLand", main);
    load_map(main, "assets/map/map.tmx", RENDER_MAP);
    load_map(main, "assets/map/map_collisions.tmx", COLLISIONS_MAP);
    if (main->map == NULL || main->collisions_map == NULL) {
        my_putstr("Error: Map not loaded\n");
        return 84;
    }
    screen_manager(main);
    free_rpg(main);
    destroy_window(main);
    return 0;
}
