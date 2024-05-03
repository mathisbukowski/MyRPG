/*
** EPITECH PROJECT, 2024
** rpg_dev
** File description:
** player_moov_function.c
*/
#include "rpg.h"

static void update_player(entity_t *player)
{
    if (player->rect.left == 512)
        player->rect.left = 0;
    player->rect.left += 64;
    sfSprite_setTextureRect(player->sprite, player->rect);
}

void left_action(rpg_t *main)
{
    entity_t *player = find_entity(main, "player");

    if (player->type == L_ANIMATED) {
        update_player(player);
    } else {
        sfTexture_destroy(player->texture);
        player->texture = sfTexture_createFromFile(
            "assets/player/walk/left.png",
            NULL);
        player->rect.top = 0;
        player->rect.left = 0;
        player->rect.width = 64;
        player->rect.height = 64;
        sfSprite_setTexture(player->sprite, player->texture, sfTrue);
        sfSprite_setTextureRect(player->sprite, player->rect);
        player->type = L_ANIMATED;
    }
}

void right_action(rpg_t *main)
{
    entity_t *player = find_entity(main, "player");

    if (player->type == R_ANIMATED) {
        update_player(player);
    } else {
        sfTexture_destroy(player->texture);
        player->texture = sfTexture_createFromFile(
            "assets/player/walk/right.png",
            NULL);
        player->rect.top = 0;
        player->rect.left = 0;
        player->rect.width = 64;
        player->rect.height = 64;
        sfSprite_setTexture(player->sprite, player->texture, sfTrue);
        sfSprite_setTextureRect(player->sprite, player->rect);
        player->type = R_ANIMATED;
    }
}

void up_action(rpg_t *main)
{
    entity_t *player = find_entity(main, "player");

    if (player->type == U_ANIMATED) {
        update_player(player);
    } else {
        sfTexture_destroy(player->texture);
        player->texture = sfTexture_createFromFile(
            "assets/player/walk/back.png",
            NULL);
        player->rect.top = 0;
        player->rect.left = 0;
        player->rect.width = 64;
        player->rect.height = 64;
        sfSprite_setTexture(player->sprite, player->texture, sfTrue);
        sfSprite_setTextureRect(player->sprite, player->rect);
        player->type = U_ANIMATED;
    }
}

void down_action(rpg_t *main)
{
    entity_t *player = find_entity(main, "player");

    if (player->type == D_ANIMATED) {
        update_player(player);
    } else {
        sfTexture_destroy(player->texture);
        player->texture = sfTexture_createFromFile(
            "assets/player/walk/front.png",
            NULL);
        player->rect.top = 0;
        player->rect.left = 0;
        player->rect.width = 64;
        player->rect.height = 64;
        sfSprite_setTexture(player->sprite, player->texture, sfTrue);
        sfSprite_setTextureRect(player->sprite, player->rect);
        player->type = D_ANIMATED;
    }
}
