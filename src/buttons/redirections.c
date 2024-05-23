/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** redirections.C
*/

#include "rpg.h"

void open_params(rpg_t *main)
{
    scene_t *new = NULL;

    new = find_scene(main->scene_manager, "paramsScene");
    main->scene_manager->current = new;
}

void open_start(rpg_t *main)
{
    scene_t *new = NULL;

    new = find_scene(main->scene_manager, "startScene");
    main->scene_manager->current = new;
}

void open_game(rpg_t *main)
{
    scene_t *new = NULL;

    new = find_scene(main->scene_manager, "gameScene");
    main->scene_manager->current = new;
}
