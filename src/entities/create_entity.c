/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** create_sprite.c
*/

#include "rpg.h"

static int destroy_and_recreate_sprite(entity_t *entity, char const *path)
{
    sfSprite_destroy(entity->sprite);
    sfTexture_destroy(entity->texture);
    entity->texture = sfTexture_createFromFile(path, NULL);
    entity->sprite = sfSprite_create();
    if (!check_texture(entity->sprite, entity->texture))
        return 0;
    sfTexture_destroy(entity->texture);
    sfSprite_destroy(entity->sprite);
    free(entity->name);
    free(entity);
    return 1;
}

static int already_in(entity_t *current, entity_t **prev,
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

static void add_to_linked(entity_t **head, entity_t *prev, entity_t *new_node)
{
    if (prev != NULL)
        prev->next = new_node;
    else
        *head = new_node;
}

static entity_t *create_new_sprite(entity_t **head, entity_t *prev,
    const entity_params_t *params, char const *path)
{
    entity_t *new_node = malloc(sizeof(entity_t));

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
    new_node->position = params->pos;
    new_node->type = params->type;
    new_node->state = true;
    sfSprite_setPosition(new_node->sprite, new_node->position);
    new_node->next = NULL;
    add_to_linked(head, prev, new_node);
    return new_node;
}

void add_entity_to_list(rpg_t *main, entity_params_t params, char const *path)
{
    entity_t *current = main->entities;
    entity_t *prev = NULL;
    entity_t *new_node = NULL;

    if (current == NULL)
        return;
    if (already_in(current, &prev, params.name, path) == 0)
        return;
    new_node = create_new_sprite(&(main->entities), prev, &params, path);
    if (new_node == NULL) {
        fprintf(stderr, "Failed to create a new event.\n");
        return;
    }
    new_node->name = strdup(params.name);
    if (new_node->name == NULL) {
        fprintf(stderr, "Failed to put a name");
        new_node->name = NULL;
    }
}
