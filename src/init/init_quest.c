/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** init_quest.c
*/

#include "rpg.h"

quest_t *init_quest(void)
{
    quest_t *new_quest = malloc(sizeof(quest_t));

    if (new_quest != NULL)
        memset(new_quest, 0, sizeof(quest_t));
    return new_quest;
}
