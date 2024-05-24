/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** NPCs.c
*/

#include "rpg.h"

void create_npc(rpg_t *main, char *name, sfVector2f pos,
    sfIntRect interact_rect)
{
    add_entity_to_list(main, (entity_params_t){name, pos, PLAYER},
        "assets/NPCs/black-smith.png");
}