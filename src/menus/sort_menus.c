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

static int bubble_sort(menu_node_t **head, menu_node_t *lastPtr)
{
    int swapped = 0;
    menu_node_t *currPtr = *head;

    while (currPtr != NULL && currPtr->next != lastPtr) {
        if (currPtr->menu->y_index > currPtr->next->menu->y_index) {
            swap_nodes(head, currPtr, currPtr->next);
            swapped = 1;
        }
        currPtr = currPtr->next;
    }
    return swapped;
}

void sort_menus(menu_node_t **head)
{
    int swapped;
    menu_node_t *lastPtr = NULL;

    if (head == NULL)
        return;
    do {
        swapped = bubble_sort(head, lastPtr);
        lastPtr = (*head)->next;
    } while (swapped);
}
