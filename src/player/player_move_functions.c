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
    animation_interval = 0.12 / player->speed;
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

    if (player->type == L_ANIMATED) {
        update_player_animation(player);
        player->pos.x -= player->speed;
    } else {
        player->rect.top = 64;
        player->rect.left = 0;
        sfSprite_setTextureRect(player->sprite, player->rect);
        player->type = L_ANIMATED;
        if (player->clock == NULL)
            player->clock = sfClock_create();
        else
            sfClock_restart(player->clock);
    }
}

void right_action(rpg_t *main)
{
    entity_t *player = find_entity(main, "player");

    if (player->type == R_ANIMATED) {
        update_player_animation(player);
        player->pos.x += player->speed;
    } else {
        player->rect.top = 192;
        player->rect.left = 0;
        sfSprite_setTextureRect(player->sprite, player->rect);
        player->type = R_ANIMATED;
        if (player->clock == NULL)
            player->clock = sfClock_create();
        else
            sfClock_restart(player->clock);
    }
}

void up_action(rpg_t *main)
{
    entity_t *player = find_entity(main, "player");

    if (player->type == U_ANIMATED) {
        update_player_animation(player);
        player->pos.y -= player->speed;
    } else {
        player->rect.top = 0;
        player->rect.left = 0;
        sfSprite_setTextureRect(player->sprite, player->rect);
        player->type = U_ANIMATED;
        if (player->clock == NULL)
            player->clock = sfClock_create();
        else
            sfClock_restart(player->clock);
    }
}

void down_action(rpg_t *main)
{
    entity_t *player = find_entity(main, "player");

    if (player->type == D_ANIMATED) {
        update_player_animation(player);
        player->pos.y += player->speed;
    } else {
        player->rect.top = 128;
        player->rect.left = 0;
        sfSprite_setTextureRect(player->sprite, player->rect);
        player->type = D_ANIMATED;
        if (player->clock == NULL)
            player->clock = sfClock_create();
        else
            sfClock_restart(player->clock);
    }
}

void update_view(rpg_t *main)
{
    entity_t *player = find_entity(main, "player");
    sfVector2f center = {player->pos.x, player->pos.y};

    sfView_setCenter(main->view, center);
    sfRenderWindow_setView(main->window->renderWindow, main->view);
}