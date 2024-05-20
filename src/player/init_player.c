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

    add_entity_to_list(main, (entity_params_t){"player",
        (sfVector2f){928, 508}, PLAYER}, "assets/player/player.png");
    player = find_entity(main, "player");
    sfSprite_setTextureRect(player->sprite, player->rect);
    add_key_to_keymap(&(main->keymap), sfKeyZ, &up_action);
    add_key_to_keymap(&(main->keymap), sfKeyD, &right_action);
    add_key_to_keymap(&(main->keymap), sfKeyQ, &left_action);
    add_key_to_keymap(&(main->keymap), sfKeyS, &down_action);
}
