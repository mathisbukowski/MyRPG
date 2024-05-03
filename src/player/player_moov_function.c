/*
** EPITECH PROJECT, 2024
** rpg_dev
** File description:
** player_moov_function.c
*/
#include "rpg.h"

static void update_player(entity_t *player)
{
    sfTime time;
    float seconds;

    time = sfClock_getElapsedTime(player->clock);
    seconds = time.microseconds / 1000000.0f;
    if (seconds > 0.05) {
        if (player->rect.left == 512)
            player->rect.left = 0;
        player->rect.left += 64;
        sfSprite_setTextureRect(player->sprite, player->rect);
        sfClock_restart(player->clock);
    }
}

void left_action(rpg_t *main)
{
    entity_t *player = find_entity(main, "player");

    if (player->type == L_ANIMATED) {
        update_player(player);
    } else {
        sfTexture_destroy(player->texture);
        player->texture = sfTexture_createFromFile(
            "assets/player/walk/left.png", NULL);
        player->rect.top = 0;
        player->rect.left = 0;
        player->rect.width = 64;
        player->rect.height = 64;
        sfSprite_setTexture(player->sprite, player->texture, sfTrue);
        sfSprite_setTextureRect(player->sprite, player->rect);
        player->type = L_ANIMATED;
        if (player->clock == NULL)
            player->clock = sfClock_create();
        sfClock_restart(player->clock);
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
            "assets/player/walk/right.png", NULL);
        player->rect.top = 0;
        player->rect.left = 0;
        player->rect.width = 64;
        player->rect.height = 64;
        sfSprite_setTexture(player->sprite, player->texture, sfTrue);
        sfSprite_setTextureRect(player->sprite, player->rect);
        player->type = R_ANIMATED;
        if (player->clock == NULL)
            player->clock = sfClock_create();
        sfClock_restart(player->clock);
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
            "assets/player/walk/back.png", NULL);
        player->rect.top = 0;
        player->rect.left = 0;
        player->rect.width = 64;
        player->rect.height = 64;
        sfSprite_setTexture(player->sprite, player->texture, sfTrue);
        sfSprite_setTextureRect(player->sprite, player->rect);
        player->type = U_ANIMATED;
        if (player->clock == NULL)
            player->clock = sfClock_create();
        sfClock_restart(player->clock);
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
            "assets/player/walk/front.png", NULL);
        player->rect.top = 0;
        player->rect.left = 0;
        player->rect.width = 64;
        player->rect.height = 64;
        sfSprite_setTexture(player->sprite, player->texture, sfTrue);
        sfSprite_setTextureRect(player->sprite, player->rect);
        player->type = D_ANIMATED;
        if (player->clock == NULL)
            player->clock = sfClock_create();
        sfClock_restart(player->clock);
    }
}
