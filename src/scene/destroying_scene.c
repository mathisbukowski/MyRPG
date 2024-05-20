/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** destroying_scene.c
*/

#include "rpg.h"

void destroying_scene(rpg_t *main)
{
    scene_t *current = main->scene_manager->head;
    scene_t *next = NULL;

    while (current != NULL) {
        next = current->next;
        if (current->destroy != NULL)
            current->destroy();
        free(current);
        current = next;
    }
    main->scene_manager->head = NULL;
    main->scene_manager->tail = NULL;
    main->scene_manager->current = NULL;
    free(main->scene_manager);
}
