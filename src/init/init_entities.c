/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** init_player.c
*/

#include "rpg.h"

player_t *init_player(void)
{
    player_t *new_player = malloc(sizeof(player_t));

    if (new_player != NULL)
        memset(new_player, 0, sizeof(player_t));
    return new_player;
}

mob_t *init_mobs(void)
{
    mob_t *new_mob = malloc(sizeof(mob_t));

    if (new_mob != NULL)
        memset(new_mob, 0, sizeof(mob_t));
    return new_mob;
}

object_t *init_object(void)
{
    object_t *new_object = malloc(sizeof(object_t));

    if (new_object != NULL)
        memset(new_object, 0, sizeof(object_t));
    return new_object;
}

void init_background(rpg_t *main)
{
    main->background_sprite = NULL;
    main->background_texture = NULL;
}
