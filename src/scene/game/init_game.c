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
    entity_displayer(main, "player");
}

static void configure_game_scene(scene_t *scene)
{
    scene->draw = render_game;
    scene->update_scene = NULL;
    scene->name = strdup("gameScene");
    scene->destroy = destroy_scene;
}

void define_params_button(rpg_t *main, sfVector2f menu_pos, scene_t *scene)
{
    sfVector2f button_pos = {0, 0};

    create_button((button_params_t){"OpenParams", button_pos,
    (sfVector2f){200, 50}, sfBlue, sfBlue,
    &(text_infos_t){"Settings", main->utils->font,
    (sfVector2f){4, 4},
    sfBlack, 30}, "gameMenu", &open_params}, main, scene);
}

void init_game_scene(rpg_t *main)
{
    scene_t *scene = malloc(sizeof(scene_t));
    sfVector2f menu_size = {200, 50};
    float x_ratio = 1700.0f / 1920.0f;
    float y_ratio = 5.0f / 1080.0f;
    sfVector2f menu_pos = {
    main->window->mode.width * x_ratio,
    main->window->mode.height * y_ratio
    };

    if (scene == NULL)
        return;
    memset(scene, 0, sizeof(scene_t));
    create_menu((menu_params_t){"gameMenu", menu_pos,
    menu_size, 0, sfTransparent, NULL, NULL, 0}, scene, main);
    define_params_button(main, menu_pos, scene);
    configure_game_scene(scene);
    add_scene(main, scene);
}
