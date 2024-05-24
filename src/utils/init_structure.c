/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** init_structure.c
*/

#include "rpg.h"

static void init_values(rpg_t *main)
{
    main->elapsed = 0.0f;
    main->map = NULL;
    main->entities = NULL;
}

rpg_t *init_structure(void)
{
    rpg_t *main = malloc(sizeof(rpg_t));

    if (main != NULL) {
        main->events = init_event();
        main->player = init_player();
        main->mobs = init_mobs();
        main->objs = init_object();
        main->quests = init_quest();
        main->window = init_window();
        main->keymap = init_keymap();
        main->utils = init_util();
        main->scene_manager = init_scene();
        main->global = sfClock_create();
        main->view = sfView_create();
        init_fps(main);
        init_values(main);
        main->inventory = init_inventory_sprite(main);
    } else
        free_rpg(main);
    return main;
}
