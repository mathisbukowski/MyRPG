/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** init_start.c
*/

#include "rpg.h"

static void create_fps_button(const rpg_t *main, sfVector2f *button_size,
    scene_t *scene, sfVector2f fps_pos)
{
    sfVector2f sixty_fps_pos = {fps_pos.x - 500, fps_pos.y + 150};
    sfVector2f hundred_twenty_fps_pos = {fps_pos.x, fps_pos.y + 150};
    sfVector2f two_hundred_fourty_fps_pos = {fps_pos.x + 500, fps_pos.y + 150};

    create_button((button_params_t){"60", sixty_fps_pos,
        (*button_size), sfBlue, sfBlue,
        &(text_infos_t){"60", main->utils->font,
        (sfVector2f){(*button_size).x / 10, (*button_size).y / 4},
        sfBlack, 30}, "paramsMenu", set_window_fps_to_sixty}, main, scene);
    create_button((button_params_t){"100", hundred_twenty_fps_pos,
        (*button_size), sfBlue, sfBlue,
        &(text_infos_t){"100", main->utils->font,
        (sfVector2f){(*button_size).x / 10, (*button_size).y / 4},
        sfBlack, 30}, "paramsMenu", set_window_fps_to_hundred}, main, scene);
    create_button((button_params_t){"120", two_hundred_fourty_fps_pos,
        (*button_size), sfBlue, sfBlue,
        &(text_infos_t){"120", main->utils->font,
        (sfVector2f){(*button_size).x / 10, (*button_size).y / 4},
        sfBlack, 30}, "paramsMenu", set_window_fps_to_hundred_twenty},
        main, scene);
}

void define_fps_button(rpg_t *main,
    sfVector2f button_size, sfVector2f fps_pos, scene_t *scene)
{
    create_button((button_params_t){"FPS", fps_pos,
    button_size, sfBlue, sfBlue,
    &(text_infos_t){"FPS", main->utils->font,
    (sfVector2f){button_size.x / 10, button_size.y / 4},
    sfBlack, 30}, "paramsMenu", NULL}, main, scene);
    create_fps_button(main, &button_size, scene, fps_pos);
}

static void set_window_size_to_full(rpg_t *main)
{
    main->window->mode.width = 1920;
    main->window->mode.height = 1080;
    sfRenderWindow_destroy(main->window->renderWindow);
    main->window->renderWindow = sfRenderWindow_create(main->window->mode,
        "RPGLand", sfDefaultStyle, NULL);
}

static void set_window_size_to_windowed(rpg_t *main)
{
    main->window->mode.width = 1280;
    main->window->mode.height = 720;
    sfRenderWindow_destroy(main->window->renderWindow);
    main->window->renderWindow = sfRenderWindow_create(main->window->mode,
        "RPGLand", sfDefaultStyle, NULL);
}

static void create_screen_size_button(const rpg_t *main,
    sfVector2f *button_size, sfVector2f *options_pos, scene_t *scene)
{
    create_button((button_params_t){"Fullscreen",
        (sfVector2f){(*options_pos).x - 500, (*options_pos).y + 150},
        (*button_size), sfBlue, sfBlue,
        &(text_infos_t){"Fullscreen", main->utils->font,
        (sfVector2f){(*button_size).x / 10, (*button_size).y / 4},
        sfBlack, 30}, "paramsMenu",
        set_window_size_to_full}, main, scene);
    create_button((button_params_t){"Windowed",
        (sfVector2f){(*options_pos).x, (*options_pos).y + 150},
        (*button_size), sfBlue, sfBlue,
        &(text_infos_t){"Windowed", main->utils->font,
        (sfVector2f){(*button_size).x / 10, (*button_size).y / 4},
        sfBlack, 30}, "paramsMenu", set_window_size_to_windowed}, main, scene);
    create_button((button_params_t){"Borderless",
        (sfVector2f){(*options_pos).x + 500, (*options_pos).y + 150},
        (*button_size), sfBlue, sfBlue,
        &(text_infos_t){"Borderless", main->utils->font,
        (sfVector2f){(*button_size).x / 10, (*button_size).y / 4},
        sfBlack, 30}, "paramsMenu",
        set_window_size_to_full}, main, scene);
}

void define_screen_button(rpg_t *main,
    sfVector2f button_size, sfVector2f options_pos, scene_t *scene)
{
    create_button((button_params_t){"Screen size", options_pos,
    button_size, sfBlue, sfBlue,
    &(text_infos_t){"Screen size", main->utils->font,
    (sfVector2f){button_size.x / 10, button_size.y / 4},
    sfBlack, 30}, "paramsMenu", NULL}, main, scene);
    create_screen_size_button(main, &button_size, &options_pos, scene);
}

void define_exit_params_button(rpg_t *main,
    sfVector2f button_size, sfVector2f exit_pos, scene_t *scene)
{
    create_button((button_params_t){"Main menu",
        {exit_pos.x, exit_pos.y + 150},
        button_size, sfBlue, sfBlue,
        &(text_infos_t){"Go to main menu", main->utils->font,
        (sfVector2f){button_size.x / 10, button_size.y / 4},
        sfBlack, 30}, "paramsMenu", &open_start}, main, scene);
}

void render_params(scene_t *scene, rpg_t *main)
{
    sfRenderWindow_drawSprite(main->window->renderWindow,
    main->background_sprite, NULL);
    render_scene(scene, main);
}

static void define_scene(scene_t *scene)
{
    scene->draw = render_params;
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
    sfVector2f fps_pos = {600 / 2 - 400 / 2, 600 / 2 - 1.5 * 100 - 200};
    sfVector2f options_pos = {600 / 2 - 400 / 2, 600 / 2 - 0.5 * 100};
    sfVector2f exit_pos = {600 / 2 - 400 / 2, 600 / 2 + 0.5 * 100 + 50};

    if (scene == NULL)
        return;
    scene = memset(scene, 0, sizeof(scene_t));
    create_menu((menu_params_t){"paramsMenu", menu_pos,
    msize, 0, sfTransparent, NULL, NULL, 0}, scene, main);
    define_fps_button(main, bsize, fps_pos, scene);
    define_screen_button(main, bsize, options_pos, scene);
    define_exit_params_button(main, bsize, exit_pos, scene);
    define_scene(scene);
    add_scene(main, scene);
}
