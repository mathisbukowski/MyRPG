/*
** EPITECH PROJECT, 2024
** rpg_dev
** File description:
** player_stand_function.c
*/
#include "rpg.h"

void player_stand_left(entity_t *player)
{
    player->rect.top = 64;
    player->rect.left = 0;
    sfSprite_setTextureRect(player->sprite, player->rect);
    player->type = PLAYER;
}

void player_stand_up(entity_t *player)
{
    player->rect.top = 0;
    player->rect.left = 0;
    sfSprite_setTextureRect(player->sprite, player->rect);
    player->type = PLAYER;
}

void player_stand_down(entity_t *player)
{
    player->rect.top = 128;
    player->rect.left = 0;
    sfSprite_setTextureRect(player->sprite, player->rect);
    player->type = PLAYER;
}

void player_stand_right(entity_t *player)
{
    player->rect.top = 192;
    player->rect.left = 0;
    sfSprite_setTextureRect(player->sprite, player->rect);
    player->type = PLAYER;
}

void player_no_action(entity_t *player)
{
    if (player->type == L_ANIMATED)
        player_stand_left(player);
    if (player->type == R_ANIMATED)
        player_stand_right(player);
    if (player->type == U_ANIMATED)
        player_stand_up(player);
    if (player->type == D_ANIMATED)
        player_stand_down(player);
}
