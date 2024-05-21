/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** init_start.c
*/

#include "rpg.h"

void define_start_butto(rpg_t *main,
    sfVector2f button_size, sfVector2f start_pos, scene_t *scene)
{
    create_button((button_params_t){"Start Game", start_pos,
    button_size, sfBlue, sfBlue,
    &(text_infos_t){"Start Game", main->utils->font,
    (sfVector2f){button_size.x / 10, button_size.y / 4},
    sfBlack, 30}, "paramsMenu", NULL}, main, scene);
}

void define_options_butto(rpg_t *main,
    sfVector2f button_size, sfVector2f options_pos, scene_t *scene)
{
    create_button((button_params_t){"coucou", options_pos,
    button_size, sfBlue, sfBlue,
    &(text_infos_t){"coucou", main->utils->font,
    (sfVector2f){button_size.x / 10, button_size.y / 4},
    sfBlack, 30}, "paramsMenu", NULL}, main, scene);
}

void define_exit_butto(rpg_t *main,
    sfVector2f button_size, sfVector2f exit_pos, scene_t *scene)
{
    create_button((button_params_t){"SOUND", exit_pos,
    button_size, sfBlue, sfBlue,
    &(text_infos_t){"SOUND", main->utils->font,
    (sfVector2f){button_size.x / 10, button_size.y / 4},
    sfBlack, 30}, "paramsMenu", NULL}, main, scene);
}

static void define_scene(scene_t *scene)
{
    scene->draw = render_scene;
    scene->update_scene = NULL;
    scene->name = strdup("paramsScene");
}

void init_params_scene(rpg_t *main)
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
    scene->menus = NULL;
    create_menu((menu_params_t){"paramsMenu", menu_pos,
    msize, 0, sfTransparent, NULL, NULL, 0}, scene, main);
    define_start_butto(main, bsize, start_pos, scene);
    define_options_butto(main, bsize, options_pos, scene);
    define_exit_butto(main, bsize, exit_pos, scene);
    define_scene(scene);
    add_scene(main, scene);
}
