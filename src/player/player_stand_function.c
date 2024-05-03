/*
** EPITECH PROJECT, 2024
** rpg_dev
** File description:
** player_stand_function.c
*/
#include "rpg.h"

void player_stand_left(entity_t *player)
{
    sfTexture_destroy(player->texture);
    player->texture = sfTexture_createFromFile(
        "assets/player/stand/left.png", NULL);
    player->rect.top = 0;
    player->rect.left = 0;
    sfSprite_setTexture(player->sprite, player->texture, sfTrue);
    player->type = PLAYER;
}

void player_stand_up(entity_t *player)
{
    sfTexture_destroy(player->texture);
    player->texture = sfTexture_createFromFile(
        "assets/player/stand/back.png", NULL);
    player->rect.top = 0;
    player->rect.left = 0;
    sfSprite_setTexture(player->sprite, player->texture, sfTrue);
    player->type = PLAYER;
}

void player_stand_down(entity_t *player)
{
    sfTexture_destroy(player->texture);
    player->texture = sfTexture_createFromFile(
        "assets/player/stand/front.png", NULL);
    player->rect.top = 0;
    player->rect.left = 0;
    sfSprite_setTexture(player->sprite, player->texture, sfTrue);
    player->type = PLAYER;
}

void player_stand_right(entity_t *player)
{
    sfTexture_destroy(player->texture);
    player->texture = sfTexture_createFromFile(
        "assets/player/stand/right.png", NULL);
    player->rect.top = 0;
    player->rect.left = 0;
    sfSprite_setTexture(player->sprite, player->texture, sfTrue);
    player->type = PLAYER;
}

void player_no_action(rpg_t *main)
{
    entity_t *player = find_entity(main, "player");

    if (player->type == L_ANIMATED)
        player_stand_left(player);
    if (player->type == R_ANIMATED)
        player_stand_right(player);
    if (player->type == U_ANIMATED)
        player_stand_up(player);
    if (player->type == D_ANIMATED)
        player_stand_down(player);
}
