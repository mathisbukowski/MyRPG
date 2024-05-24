/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** actions.c
*/

#include "rpg.h"

void handle_entity_actions(rpg_t *rpg, entity_t *entity)
{
    entity_t *player;

    if (rpg == NULL || entity == NULL)
        return;
    player = find_entity(rpg, "player");
    if (player == NULL || entity->actions == NULL)
        return;
    entity->actions(rpg, entity, entity->interact_rect, player);
}
