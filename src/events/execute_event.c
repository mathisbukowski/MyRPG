/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** execute_event.c
*/

#include "../../include/rpg.h"

void execute_event(rpg_t *main, sfEventType type)
{
    event_t *current = main->events;

    while (current != NULL) {
        if (current->type == type)
            current->function(main);
        current = current->next;
    }
}