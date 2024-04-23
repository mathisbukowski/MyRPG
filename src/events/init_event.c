/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** init_event.c
*/

#include "../../include/rpg.h"

static event_t *create_new_event(event_t **head, event_t *prev,
    sfEvent event, void (*function)(rpg_t *))
{
    event_t *new_node = malloc(sizeof(event_t));

    if (new_node == NULL)
        return NULL;
    new_node->function = function;
    new_node->event = event;
    new_node->type = event.type;
    new_node->next = NULL;
    if (prev != NULL)
        prev->next = new_node;
    else
        *head = new_node;
    return new_node;
}

static int already_define_event(event_t *current, event_t **prev,
    void (*function)(rpg_t *), sfEventType type)
{
    while (current != NULL) {
        if (type == current->type) {
            current->function = NULL;
            current->function = function;
            return 0;
        }
        (*prev) = current;
        current = current->next;
    }
    return 1;
}

void add_event_to_list(rpg_t *main, void (*function)(rpg_t *), sfEvent event)
{
    event_t *current = main->events;
    event_t *prev = NULL;
    event_t *new_node = NULL;

    if (current == NULL)
        return;
    if (already_define_event(current, &prev, function, event.type) == 0)
        return;
    new_node = create_new_event(&(main->events), prev, event, function);
    if (new_node == NULL) {
        fprintf(stderr, "Failed to create a new event.\n");
        return;
    }
}
