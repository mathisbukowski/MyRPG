/*
** EPITECH PROJECT, 2024
** rpg_dev
** File description:
** manage_clock.c
*/
#include "rpg.h"

void manage_clock(entity_t *entity)
{
    sfTime time;
    float seconds;

    if (entity->clock == NULL)
        return;
    time = sfClock_getElapsedTime(entity->clock);
    seconds = time.microseconds / 1000000.0f;
    if (seconds > 0.1 && (entity->type == L_ANIMATED ||
        entity->type == R_ANIMATED || entity->type == U_ANIMATED ||
        entity->type == D_ANIMATED))
        player_no_action(entity);
}
