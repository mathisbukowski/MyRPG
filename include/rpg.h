/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** rpg.h
*/

#ifndef RPG_H
    #define RPG_H
    #include <SFML/System.h>
    #include <SFML/Window.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/Network.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdbool.h>
    #include <math.h>
    #include <time.h>
    #include <ctype.h>
    #include <limits.h>
    #include <float.h>
    #include <errno.h>
    #include <assert.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include "../include/my.h"
    #include "../include/my_printf.h"

// Player Structure
typedef struct player_t {
    char name[128];
    int level;
    long experience;
    int pv;
    int pc;
} player_t;

// Mob Structure
typedef struct mob_s {
    char name[128];
    int pv;
    int power;
    int defense;
    struct mob_s *next;
} mob_t;

// Object Structure

typedef enum tool_s {
    SHOVEL,
    HOE,
    SWORD,
    PICKAXE
} tool_t;

typedef struct object_s {
    char name[128];
    tool_t type;
    int power;
    char utility[1024];
    struct object_s *next;
} object_t;

// Quest Structure
typedef struct quest_s {
    char title[128];
    char desc[1024];
    bool in_progress;
    int progression;
    struct quest_s *next;
} quest_t;

// Events List
typedef struct event_s {
    sfEventType type;
    sfEvent event;
    void (*function)(sfEventType, sfEvent);
    struct event_s *next;
} event_t;

typedef struct rpg_s {
    player_t *player;
    mob_t *mobs;
    object_t *objs;
    quest_t *quests;
    event_t *events;
} rpg_t;


// Utils
int check_tty(char **env);

#endif //RPG_H
