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
    sfIntRect rect = {320, 128, 64, 64};
    sfVector2u textureSize;

    player = find_entity(main, "player");
    if (player == NULL)
        return;
    player->pos.x = 1200;
    player->pos.y = 380;
    player->speed = PLAYER_SPEED;
    sfSprite_setTextureRect(player->sprite, rect);
    sfSprite_setScale(player->sprite, (sfVector2f){0.5f, 0.5f});
    sfSprite_setOrigin(player->sprite, (sfVector2f){64 / 2.0f, 64 / 2.0f});
    sfSprite_setPosition(player->sprite, player->pos);
}
