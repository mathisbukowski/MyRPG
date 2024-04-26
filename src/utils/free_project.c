/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** free_project.c
*/

#include "rpg.h"


static void free_players(player_t *player)
{
    free(player);
}

static void free_mobs(mob_t *mob)
{
    mob_t *tmp = NULL;

    while (mob != NULL) {
        tmp = mob;
        mob = mob->next;
        free(tmp);
    }
}

static void free_objects(object_t *obj)
{
    object_t *tmp = NULL;

    while (obj != NULL) {
        tmp = obj;
        obj = obj->next;
        free(tmp);
    }
}

static void free_quests(quest_t *quest)
{
    quest_t *tmp = NULL;

    while (quest != NULL) {
        tmp = quest;
        quest = quest->next;
        free(tmp);
    }
}

static void free_events(event_t *event)
{
    event_t *tmp = NULL;

    while (event != NULL) {
        tmp = event;
        event = event->next;
        free(tmp);
    }
}

void free_keymap(keymap_t *keymap)
{
    keymap_t *tmp = NULL;

    while (keymap != NULL) {
        tmp = keymap;
        keymap = keymap->next;
        free(tmp);
    }
}

void free_rpg(rpg_t *rpg)
{
    if (rpg != NULL) {
        free_players(rpg->player);
        free_mobs(rpg->mobs);
        free_objects(rpg->objs);
        free_quests(rpg->quests);
        free_events(rpg->events);
        free_keymap(rpg->keymap);
        free_sprites(rpg->sprites);
        free(rpg);
    }
}
