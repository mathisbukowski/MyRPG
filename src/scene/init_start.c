/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** init_start.c
*/

#include "rpg.h"

void define_start_button(rpg_t *main,
    sfVector2f button_size, sfVector2f start_pos, scene_t *scene)
{
    create_button((button_params_t){"Start Game", start_pos,
    button_size, sfBlue, sfBlue,
    &(text_infos_t){"Start Game", main->utils->font,
    (sfVector2f){button_size.x / 10, button_size.y / 4},
    sfBlack, 30}, "mainMenu", &open_game}, main, scene);
}

void define_options_button(rpg_t *main,
    sfVector2f button_size, sfVector2f options_pos, scene_t *scene)
{
    create_button((button_params_t){"Settings", options_pos,
    button_size, sfBlue, sfBlue,
    &(text_infos_t){"Settings", main->utils->font,
    (sfVector2f){button_size.x / 10, button_size.y / 4},
    sfBlack, 30}, "mainMenu", &open_params}, main, scene);
}

void define_exit_button(rpg_t *main,
    sfVector2f button_size, sfVector2f exit_pos, scene_t *scene)
{
    create_button((button_params_t){"Exit", exit_pos,
    button_size, sfBlue, sfBlue,
    &(text_infos_t){"Exit", main->utils->font,
    (sfVector2f){button_size.x / 10, button_size.y / 4},
    sfBlack, 30}, "mainMenu", &close_window}, main, scene);
}

static void draw_start_menu(scene_t *current, rpg_t *main)
{
    sfRenderWindow_drawSprite(main->window->renderWindow,
    main->background_sprite, NULL);
    render_scene(current, main);
}

static void define_menu(scene_t *scene)
{
    scene->draw = draw_start_menu;
    scene->update_scene = NULL;
    scene->name = strdup("startScene");
    scene->destroy = destroy_scene;
}

void init_start_scene(rpg_t *main)
{
    sfVector2f bsize = {400, 100};
    sfVector2f msize = {600, 600};
    sfVector2f menu_pos = {(float)(main->window->mode.width - 600) / 2,
    (float)(main->window->mode.height - 600) / 2};
    scene_t *scene = malloc(sizeof(scene_t));
    sfVector2f start_pos = {600 / 2 - 400 / 2, 600 / 2 - 1.5 * 100 - 50};
    sfVector2f options_pos = {600 / 2 - 400 / 2, 600 / 2 - 0.5 * 100};
    sfVector2f exit_pos = {600 / 2 - 400 / 2, 600 / 2 + 0.5 * 100 + 50};

    if (scene == NULL)
        return;
    memset(scene, 0, sizeof(scene_t));
    create_menu((menu_params_t){"mainMenu", menu_pos,
    msize, 0, sfTransparent, NULL, NULL, 0}, scene, main);
    define_start_button(main, bsize, start_pos, scene);
    define_options_button(main, bsize, options_pos, scene);
    define_exit_button(main, bsize, exit_pos, scene);
    define_menu(scene);
    add_scene(main, scene);
}
