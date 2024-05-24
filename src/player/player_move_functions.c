/*
** EPITECH PROJECT, 2024
** rpg_dev
** File description:
** player_move_function.c
*/
#include "rpg.h"

static void update_player_animation(entity_t *player)
{
    sfTime time;
    float seconds;
    float animation_interval;

    time = sfClock_getElapsedTime(player->clock);
    seconds = time.microseconds / 1000000.0f;
    animation_interval = 0.14 / player->speed;
    if (seconds > animation_interval) {
        if (player->rect.left == 512)
            player->rect.left = 64;
        else
            player->rect.left += 64;
        sfSprite_setTextureRect(player->sprite, player->rect);
        sfClock_restart(player->clock);
    }
}

void left_action(rpg_t *main)
{
    entity_t *player = find_entity(main, "player");

    move_entity(main, player, LEFT);
    if (player->type != L_ANIMATED) {
        player->rect.top = 64;
        player->rect.left = 0;
        sfSprite_setTextureRect(player->sprite, player->rect);
        player->type = L_ANIMATED;
        if (player->clock == NULL)
            player->clock = sfClock_create();
        else
            sfClock_restart(player->clock);
    } else
        update_player_animation(player);
}

void right_action(rpg_t *main)
{
    entity_t *player = find_entity(main, "player");

    move_entity(main, player, RIGHT);
    if (player->type != R_ANIMATED) {
        player->rect.top = 192;
        player->rect.left = 0;
        sfSprite_setTextureRect(player->sprite, player->rect);
        player->type = R_ANIMATED;
        if (player->clock == NULL)
            player->clock = sfClock_create();
        else
            sfClock_restart(player->clock);
    } else
        update_player_animation(player);
}

void up_action(rpg_t *main)
{
    entity_t *player = find_entity(main, "player");

    move_entity(main, player, UP);
    if (player->type != U_ANIMATED) {
        player->rect.top = 0;
        player->rect.left = 0;
        sfSprite_setTextureRect(player->sprite, player->rect);
        player->type = U_ANIMATED;
        if (player->clock == NULL)
            player->clock = sfClock_create();
        else
            sfClock_restart(player->clock);
    } else
        update_player_animation(player);
}

void down_action(rpg_t *main)
{
    entity_t *player = find_entity(main, "player");

    move_entity(main, player, DOWN);
    if (player->type != D_ANIMATED) {
        player->rect.top = 128;
        player->rect.left = 0;
        sfSprite_setTextureRect(player->sprite, player->rect);
        player->type = D_ANIMATED;
        if (player->clock == NULL)
            player->clock = sfClock_create();
        else
            sfClock_restart(player->clock);
    } else
        update_player_animation(player);
}
