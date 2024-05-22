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

    add_entity_to_list(main, (entity_params_t){"player",
    (sfVector2f){928, 508}, PLAYER}, "assets/player/player.png");
    player = find_entity(main, "player");
    player->pos.x = main->map->width * 16 / 2;
    player->pos.y = main->map->height * 16 / 2;
    player->speed = 2.5;
    sfSprite_setTextureRect(player->sprite, rect);
    sfSprite_setScale(player->sprite, (sfVector2f){1.5, 1.5});
    add_key_to_keymap(&(main->keymap), sfKeyZ, &up_action);
    add_key_to_keymap(&(main->keymap), sfKeyD, &right_action);
    add_key_to_keymap(&(main->keymap), sfKeyQ, &left_action);
    add_key_to_keymap(&(main->keymap), sfKeyS, &down_action);
}
