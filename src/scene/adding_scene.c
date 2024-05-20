/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** adding_scene.c
*/

#include "rpg.h"

void add_scene(rpg_t *main, scene_t *new)
{
    scene_list_t *list = main->manager;

    new->next = NULL;
    if (list->tail == NULL) {
        list->head = new;
        list->tail = new;
    } else {
        list->tail->next = new;
        list->tail = new;
    }
    if (list->current == NULL)
        list->current = new;
}