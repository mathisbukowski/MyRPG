/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** find_scene.c
*/

#include "rpg.h"

scene_t *find_scene(scene_list_t *scene_list, char const *name)
{
    scene_t *current_scene = NULL;

    if (scene_list == NULL || name == NULL)
        return NULL;
    current_scene = scene_list->head;
    while (current_scene != NULL) {
        if (strcmp(current_scene->name, name) == 0)
            return current_scene;
        current_scene = current_scene->next;
    }
    return NULL;
}
