/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** execute_event.c
*/

#include "rpg.h"

void execute_event(rpg_t *main, const sfEventType type)
{
    const event_t *current = main->events;

    while (current != NULL) {
        if (current->type == type && current->function)
            current->function(main);
        current = current->next;
    }
}
