/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** init_fps.c
*/

#include "rpg.h"

void init_fps(rpg_t *main)
{
    main->fpsCounter = sfText_create();
    sfText_setFont(main->fpsCounter, main->utils->font);
    sfText_setCharacterSize(main->fpsCounter, 24);
    sfText_setPosition(main->fpsCounter, (sfVector2f){10, 10});
    main->fpsClock = sfClock_create();
}

void update_fps(rpg_t *main)
{
    sfTime time = sfClock_restart(main->fpsClock);
    float fps = 1.0f / sfTime_asSeconds(time);
    char fpsString[50];

    sprintf(fpsString, "FPS: %.2f", fps);
    sfText_setString(main->fpsCounter, fpsString);
    sfRenderWindow_drawText(main->window->renderWindow, main->fpsCounter,
        NULL);
    sfRenderWindow_display(main->window->renderWindow);
}
