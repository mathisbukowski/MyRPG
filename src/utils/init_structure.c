/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** init_structure.c
*/

#include "rpg.h"

static player_t *init_player(void)
{
    player_t *new_player = malloc(sizeof(player_t));

    if (new_player != NULL)
        memset(new_player, 0, sizeof(player_t));
    return new_player;
}

static mob_t *init_mobs(void)
{
    mob_t *new_mob = malloc(sizeof(mob_t));

    if (new_mob != NULL)
        memset(new_mob, 0, sizeof(mob_t));
    return new_mob;
}

static object_t *init_object(void)
{
    object_t *new_object = malloc(sizeof(object_t));

    if (new_object != NULL)
        memset(new_object, 0, sizeof(object_t));
    return new_object;
}

static quest_t *init_quest(void)
{
    quest_t *new_quest = malloc(sizeof(quest_t));

    if (new_quest != NULL)
        memset(new_quest, 0, sizeof(quest_t));
    return new_quest;
}

static event_t *init_event(void)
{
    event_t *new_event = malloc(sizeof(event_t));

    if (new_event != NULL)
        memset(new_event, 0, sizeof(event_t));
    return new_event;
}

window_t *init_window(void)
{
    window_t *new_window = malloc(sizeof(window_t));

    if (new_window != NULL)
        memset(new_window, 0, sizeof(window_t));
    return new_window;
}

rpg_t *init_structure(void)
{
    rpg_t *main = malloc(sizeof(rpg_t));

    if (main != NULL) {
        main->events = init_event();
        main->player = init_player();
        main->mobs = init_mobs();
        main->objs = init_object();
        main->quests = init_quest();
        main->window = init_window();
    } else
        free_rpg(main);
    return main;
}
