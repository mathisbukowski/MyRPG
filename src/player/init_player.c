/*
** EPITECH PROJECT, 2024
** rpg_dev
** File description:
** init_player.c
*/
#include "rpg.h"

void init_player_sprite(rpg_t *main)
{
    entity_t *player = NULL;
    entity_t *npc = NULL;
    sfIntRect rect = {320, 128, 64, 64};

    player = find_entity(main, "player");
    player->pos.x = (main->map->width * 16 / 2);
    player->pos.y = (main->map->height * 16 / 2) - 150;
    player->speed = PLAYER_SPEED;
    sfSprite_setTextureRect(player->sprite, rect);
    sfSprite_setScale(player->sprite, (sfVector2f){2, 2});
}
