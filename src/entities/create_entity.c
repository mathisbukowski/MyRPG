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

static int already_in(entity_t *current, char const *name, char const *path)
{
    if (path == NULL)
        return 1;
    while (current != NULL) {
        if (current->name != NULL && strcmp(current->name, name) == 0)
            return destroy_and_recreate_sprite(current, path);
        current = current->next;
    }
    return 1;
}

static void add_to_linked(entity_t **head, entity_t *new_node)
{
    entity_t *current = *head;

    if (*head == NULL) {
        *head = new_node;
        return;
    }
    while (current->next != NULL)
        current = current->next;
    current->next = new_node;
}

static void destroy_if_no_texture(entity_t *new_node)
{
    if (new_node->sprite) {
        sfSprite_destroy(new_node->sprite);
        new_node->sprite = NULL;
    }
    if (new_node->texture) {
        sfTexture_destroy(new_node->texture);
        new_node->texture = NULL;
    }
    if (new_node->name) {
        free(new_node->name);
        new_node->name = NULL;
    }
    free(new_node);
    new_node = NULL;
}

static sfIntRect init_rect(void)
{
    sfIntRect rectangle;

    rectangle.height = 64;
    rectangle.width = 64;
    rectangle.left = 0;
    rectangle.top = 0;
    return rectangle;
}

static entity_t *create_new_sprite(const entity_params_t *params,
    char const *path)
{
    entity_t *new_node = malloc(sizeof(entity_t));

    if (new_node == NULL)
        return NULL;
    memset(new_node, 0, sizeof(entity_t));
    new_node->sprite = sfSprite_create();
    new_node->texture = sfTexture_createFromFile(path, NULL);
    if (check_texture(new_node->sprite, new_node->texture)) {
        destroy_if_no_texture(new_node);
        return NULL;
    }
    if (params->type == PLAYER)
        new_node->rect = init_rect();
    new_node->clock = NULL;
    new_node->pos = params->pos;
    new_node->type = params->type;
    new_node->state = true;
    sfSprite_setPosition(new_node->sprite, new_node->pos);
    new_node->next = NULL;
    return new_node;
}

void add_entity_to_list(rpg_t *main, entity_params_t params, char const *path,
    void (*function)(rpg_t *, entity_t *, sfIntRect, entity_t *))
{
    entity_t *new_node = NULL;

    if (already_in(main->entities, params.name, path) == 0)
        return;
    new_node = create_new_sprite(&params, path);
    if (new_node == NULL) {
        fprintf(stderr, "Failed to create a new entity.\n");
        return;
    }
    new_node->name = strdup(params.name);
    if (new_node->name == NULL) {
        new_node->name = NULL;
        fprintf(stderr, "Failed to allocate memory for the entity name.\n");
        destroy_if_no_texture(new_node);
        return;
    }
    new_node->actions = function;
    add_to_linked(&(main->entities), new_node);
}
