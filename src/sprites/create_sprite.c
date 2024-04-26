/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** create_sprite.c
*/

#include "rpg.h"

static int destroy_and_recreate_sprite(sprite_t *sprite, char const *path)
{
    sfSprite_destroy(sprite->sprite);
    sfTexture_destroy(sprite->texture);
    sprite->texture = sfTexture_createFromFile(path, NULL);
    sprite->sprite = sfSprite_create();
    if (!check_texture(sprite->sprite, sprite->texture))
        return 0;
    sfTexture_destroy(sprite->texture);
    sfSprite_destroy(sprite->sprite);
    free(sprite->name);
    free(sprite);
    return 1;
}

static int already_in(sprite_t *current, sprite_t **prev,
    char const *name, char const *path)
{
    while (current != NULL) {
        if (current->name != NULL && strcmp(current->name, name) == 0)
            return destroy_and_recreate_sprite(current, path);
        *prev = current;
        current = current->next;
    }
    return 1;
}

static void add_to_linked(sprite_t **head, sprite_t *prev, sprite_t *new_node)
{
    if (prev != NULL)
        prev->next = new_node;
    else
        *head = new_node;
}

static sprite_t *create_new_sprite(sprite_t **head, sprite_t *prev,
    sfVector2f pos, char const *path)
{
    sprite_t *new_node = malloc(sizeof(sprite_t));

    if (new_node == NULL)
        return NULL;
    new_node->sprite = sfSprite_create();
    new_node->texture = sfTexture_createFromFile(path, NULL);
    if (check_texture(new_node->sprite, new_node->texture)) {
        sfSprite_destroy(new_node->sprite);
        sfTexture_destroy(new_node->texture);
        free(new_node->name);
        free(new_node);
        return NULL;
    }
    new_node->position = pos;
    new_node->state = true;
    sfSprite_setPosition(new_node->sprite, new_node->position);
    new_node->next = NULL;
    add_to_linked(head, prev, new_node);
    return new_node;
}

void add_sprite_to_list(rpg_t *main, sfVector2f position,
    char const *path, char const *name)
{
    sprite_t *current = main->sprites;
    sprite_t *prev = NULL;
    sprite_t *new_node = NULL;

    if (current == NULL)
        return;
    if (already_in(current, &prev, name, path) == 0)
        return;
    new_node = create_new_sprite(&(main->sprites), prev, position, path);
    if (new_node == NULL) {
        fprintf(stderr, "Failed to create a new event.\n");
        return;
    }
    new_node->name = strdup(name);
    if (!new_node->name) {
        fprintf(stderr, "Failed to put a name");
        new_node->name = NULL;
    }
}
