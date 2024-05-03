/*
** EPITECH PROJECT, 2024
** rpg_dev
** File description:
** init_player.c
*/
#include "rpg.h"

void init_player_sprite(rpg_t *main)
{
    add_entity_to_list(main, (entity_params_t){"player",
        (sfVector2f){928, 508}, PLAYER}, "assets/player/stand/front.png");
    add_key_to_keymap(&(main->keymap), sfKeyZ, &up_action);
    add_key_to_keymap(&(main->keymap), sfKeyD, &right_action);
    add_key_to_keymap(&(main->keymap), sfKeyQ, &left_action);
    add_key_to_keymap(&(main->keymap), sfKeyS, &down_action);
}
