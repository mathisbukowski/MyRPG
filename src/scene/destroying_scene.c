/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** destroying_scene.c
*/

#include "rpg.h"

void destroying_scene(rpg_t *main)
{
    scene_t *current = main->manager->head;
    scene_t *next = NULL;

    while (current != NULL) {
        next = current->next;
        if (current->destroy != NULL)
            current->destroy();
        free(current);
        current = next;
    }
    main->manager->head = NULL;
    main->manager->tail = NULL;
    main->manager->current = NULL;
    free(main->manager);
}