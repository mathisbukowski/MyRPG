/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** destroying_scene.c
*/

#include "rpg.h"

void destroy_scene(scene_t *scene)
{
    free(scene->name);
    destroy_menu(scene->menus);
}

void destroying_scenes(rpg_t *main)
{
    scene_t *current = main->scene_manager->head;
    scene_t *next = NULL;

    while (current != NULL) {
        next = current->next;
        destroy_scene(current);
        free(current);
        current = next;
    }
    main->scene_manager->head = NULL;
    main->scene_manager->tail = NULL;
    main->scene_manager->current = NULL;
    free(main->scene_manager);
}
