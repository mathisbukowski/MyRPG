/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** init_tools.c
*/

#include "rpg.h"


event_t *init_event(void)
{
    event_t *new_event = malloc(sizeof(event_t));

    if (new_event != NULL)
        memset(new_event, 0, sizeof(event_t));
    return new_event;
}

window_t *init_window(void)
{
    window_t *new_window = malloc(sizeof(window_t));

    if (new_window != NULL)
        memset(new_window, 0, sizeof(window_t));
    return new_window;
}

keymap_t *init_keymap(void)
{
    keymap_t *new_keymap = malloc(sizeof(keymap_t));

    if (new_keymap != NULL)
        memset(new_keymap, 0, sizeof(keymap_t));
    return new_keymap;
}

util_t *init_util(void)
{
    util_t *new_util = malloc(sizeof(util_t));

    if (new_util == NULL)
        return NULL;
    memset(new_util, 0, sizeof(util_t));
    new_util->font = sfFont_createFromFile("assets/font/font.ttf");
    return new_util;
}

scene_list_t *init_scene(void)
{
    scene_list_t *scene_list = malloc(sizeof(scene_list_t));

    if (scene_list == NULL)
        return NULL;
    memset(scene_list, 0, sizeof(scene_list_t));
    scene_list->head = NULL;
    scene_list->tail = NULL;
    scene_list->current = NULL;
    return scene_list;
}
