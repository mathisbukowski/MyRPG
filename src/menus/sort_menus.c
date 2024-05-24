/*
** EPITECH PROJECT, 2024
** B-MUL-200-LIL-2-1-mypaint-raphael.richaud
** File description:
** sort_menus.c
*/

#include "rpg.h"

static void swap_nodes(menu_node_t **head, menu_node_t *node1,
    menu_node_t *node2)
{
    menu_node_t *temp;
    menu_node_t *prev;

    if (*head == node1)
        *head = node2;
    else {
        prev = *head;
        while (prev->next != node1)
            prev = prev->next;
        prev->next = node2;
    }
    temp = node2->next;
    node2->next = node1;
    node1->next = temp;
}

static int bubble_sort(menu_node_t **head, menu_node_t *last_ptr)
{
    int swapped = 0;
    menu_node_t *curr_ptr = *head;

    while (curr_ptr != NULL && curr_ptr->next != last_ptr) {
        if (curr_ptr->menu->y_index > curr_ptr->next->menu->y_index) {
            swap_nodes(head, curr_ptr, curr_ptr->next);
            swapped = 1;
        }
        curr_ptr = curr_ptr->next;
    }
    return swapped;
}

void sort_menus(menu_node_t **head)
{
    int swapped;
    menu_node_t *last_ptr = NULL;

    if (head == NULL)
        return;
    do {
        swapped = bubble_sort(head, last_ptr);
        last_ptr = (*head)->next;
    } while (swapped);
}
