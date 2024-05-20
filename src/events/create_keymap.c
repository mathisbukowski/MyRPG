/*
** EPITECH PROJECT, 2024
** myrpg
** File description:
** create_keymap.c
*/

#include "rpg.h"

keymap_t *create_keymap_node(const sfKeyCode key, void (*function)(rpg_t *))
{
    keymap_t *new_node = malloc(sizeof(keymap_t));

    if (new_node == NULL) {
        fprintf(stderr, "Failed to allocate memory for keymap node.\n");
        return NULL;
    }
    new_node->key = key;
    new_node->function = function;
    new_node->next = NULL;
    return new_node;
}

void add_key_to_keymap(keymap_t **head, const sfKeyCode key,
    void (*function)(rpg_t *))
{
    keymap_t *current = *head;

    if (current == NULL) {
        *head = create_keymap_node(key, function);
        return;
    }
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = create_keymap_node(key, function);
}

void handle_key_press(rpg_t *main, const sfKeyCode key)
{
    keymap_t *current = main->keymap;

    while (current != NULL) {
        if (current->key == key) {
            current->function(main);
        }
        current = current->next;
    }
}
