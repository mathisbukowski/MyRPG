/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** init_game.c
*/

#include "rpg.h"

void render_game(scene_t *current, rpg_t *main)
{
    render_scene(current, main);
}

static void configure_game_scene(scene_t *scene)
{
    scene->draw = render_game;
    scene->update_scene = NULL;
    scene->name = strdup("gameScene");
    scene->destroy = destroy_scene;
}

void init_game_scene(rpg_t *main)
{
    scene_t *scene = malloc(sizeof(scene_t));

    if (scene == NULL)
        return;
    memset(scene, 0, sizeof(scene_t));
    configure_game_scene(scene);
    add_scene(main, scene);
}
