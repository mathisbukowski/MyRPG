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
    #include <math.h>
    #include <stdbool.h>
    #include "hud.h"
    #include "my.h"
    #include "my_printf.h"
    #include <time.h>
    #include <ctype.h>
    #include <limits.h>
    #include <float.h>
    #include <errno.h>
    #include <assert.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include "my.h"
    #include "my_printf.h"
    #include "map.h"

typedef struct rpg_s rpg_t;

typedef enum entitype_s {
    BACKGROUND,
    BUTTON_MENU,
    PLAYER,
    L_ANIMATED,
    R_ANIMATED,
    U_ANIMATED,
    D_ANIMATED,
    NONE
} entitype_t;

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

// Keymap
typedef struct keymap_s {
    sfKeyCode key;
    void (*function)(rpg_t *);
    struct keymap_s *next;
} keymap_t;

// Entity Params
typedef struct entity_params_s {
    char *name;
    sfVector2f pos;
    entitype_t type;
} entity_params_t;

// Sprite List
typedef struct entity_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfIntRect rect;
    sfClock *clock;
    float speed;
    char *name;
    entitype_t type;
    bool state;
    struct entity_s *next;
} entity_t;

// Player Structure
typedef struct player_t {
    char name[128];
    int level;
    long experience;
    int pv;
    int pc;
} player_t;

// Events List
typedef struct event_s {
    sfEventType type;
    void (*function)(rpg_t *);
    struct event_s *next;
} event_t;

// Window Structure
typedef struct window_s {
    sfRenderWindow *renderWindow;
    sfTexture *texture;
    sfVideoMode mode;
    char *title;
    unsigned int style;
    sfBool isFullscreen;
    sfBool isActive;
} window_t;

typedef struct util_s {
    sfFont *font;
} util_t;

// Main
struct rpg_s {
    player_t *player;
    mob_t *mobs;
    object_t *objs;
    quest_t *quests;
    event_t *events;
    window_t *window;
    keymap_t *keymap;
    entity_t *entities;
    util_t *utils;
    scene_list_t *scene_manager;
    scene_t *current_scene;
    map_t *map;
    sfView *view;
};

// Main Category
int game_logic(int ac, char **av);

// Utils
int check_tty(char **env);
void free_rpg(rpg_t *rpg);
rpg_t *init_structure(void);
entity_t *find_entity(rpg_t *main, char *entity_name);
int check_texture(sfSprite *sprite, const sfTexture *texture);
char *remove_spaces(char *str);

// Window Manager
void create_window(unsigned int width, unsigned int height,
    const char *title, rpg_t *main);
void event_manager(rpg_t *main);
void display_window(rpg_t *main);
void destroy_window(rpg_t *main);

// Help Category
int print_help(int ac, char **av);

// Event Manager
void add_event_to_list(rpg_t *main, void (*function)(rpg_t *),
    sfEventType type);
void execute_event(rpg_t *main, sfEventType type);
void close_window(rpg_t *main);

// Keymap
keymap_t *create_keymap_node(sfKeyCode key, void (*function)(rpg_t *));
void add_key_to_keymap(keymap_t **head, sfKeyCode key,
    void (*function)(rpg_t *));
void handle_key_press(rpg_t *main, sfKeyCode key);

// Sprite Manager
void free_entities(entity_t *entities);
void entity_displayer(rpg_t *main);
void add_entity_to_list(rpg_t *main, entity_params_t params,
    char const *path);
void init_player_sprite(rpg_t *main);
void left_action(rpg_t *main);
void right_action(rpg_t *main);
void up_action(rpg_t *main);
void down_action(rpg_t *main);
void player_no_action(entity_t *player);

//Clock Manager
void manage_clock(entity_t *entity);

// Init
quest_t *init_quest(void);
event_t *init_event(void);
window_t *init_window(void);
keymap_t *init_keymap(void);
util_t *init_util(void);
player_t *init_player(void);
mob_t *init_mobs(void);
object_t *init_object(void);
entity_t *init_entity(void);
scene_list_t *init_scene(void);

// Scenes
void add_scene(rpg_t *main, scene_t *new);
void destroying_scene(rpg_t *main);
void draw_start(rpg_t *main);
void init_start_scene(rpg_t *main);
scene_t *find_scene(scene_list_t *scene_list, char const *name);
void destroy_scene(scene_t *scene);
void init_params_scene(rpg_t *main);
void destroying_scenes(rpg_t *main);

void saving_system(rpg_t *main);
void loading_system(rpg_t *main, char **av);

// Player
void update_view(rpg_t *main);
#endif //RPG_H
