/*
** EPITECH PROJECT, 2024
** rpg_dev
** File description:
** find_entity.c
*/
#include "rpg.h"

entity_t *find_entity(rpg_t *main, char *entity_name)
{
    entity_t *current = main->entities;

    while (my_strcmp(entity_name, current->name)) {
        current = current->next;
    }
    return current;
}