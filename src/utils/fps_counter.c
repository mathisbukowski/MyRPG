/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** init_fps.c
*/

#include "rpg.h"

void init_fps(rpg_t *main)
{
    main->fps_counter = sfText_create();
    sfText_setFont(main->fps_counter, main->utils->font);
    sfText_setCharacterSize(main->fps_counter, 24);
    sfText_setPosition(main->fps_counter, (sfVector2f){10, 10});
    main->fps_clock = sfClock_create();
}

void update_fps(rpg_t *main)
{
    sfTime time = sfClock_restart(main->fps_clock);
    float fps = 1.0f / sfTime_asSeconds(time);
    char fpsString[50];

    sprintf(fpsString, "FPS: %.2f", fps);
    sfText_setString(main->fps_counter, fpsString);
    sfRenderWindow_drawText(main->window->renderWindow, main->fps_counter,
        NULL);
    sfRenderWindow_display(main->window->renderWindow);
}
