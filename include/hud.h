/*
** EPITECH PROJECT, 2024
** bootstrap myPaint
** File description:
** HUD.h
*/

#ifndef HUD_H
    #define HUD_H
    #include <SFML/Graphics.h>
    #include "rpg.h"

typedef struct rpg_s rpg_t;

//forward declaration
typedef struct button_s button_t;
typedef struct menu_s menu_t;
typedef struct params_s params_t;
typedef struct button_node_s button_node_t;
typedef struct text_infos_s text_infos_t;
typedef void (*button_func_t)(rpg_t *);

//menus
typedef struct menu_s {
    char *name;
    sfRectangleShape *rect;
    sfVector2f pos;
    sfVector2f size;
    sfColor color;
    button_node_t *buttons;
    int isHover;
    int isClicked;
    int isHidden;
    int isOpen;
    int y_index;
    menu_t *subMenu;
    menu_t *parentMenu;
    sfText *text;
}menu_t;

typedef struct menu_node_s {
    menu_t *menu;
    struct menu_node_s *next;
} menu_node_t;

typedef struct menu_params_s {
    char *name;
    sfVector2f pos;
    sfVector2f size;
    int y_index;
    sfColor color;
    char *subMenuName;
    text_infos_t *text;
    int isHidden;
}menu_params_t;

int create_menu(menu_params_t menuParams, rpg_t *params);
void check_menu_hover(menu_t *menu, sfVector2i mousePos);
menu_t *find_menu_by_name(char *name, menu_node_t *head);
void sort_menus(menu_node_t **head);
void handle_menu_hover(menu_t *menu);
//buttons
typedef struct button_s {
    sfRectangleShape *rect;
    sfVector2f pos;
    sfColor color;
    sfColor hoverColor;
    sfText *text;
    int isHover;
    int isClicked;
    int isHidden;
    int isSelected;
    menu_t *linkedMenu;
    button_func_t action;
}button_t;

typedef struct button_node_s {
    button_t *button;
    struct button_node_s *next;
}button_node_t;

typedef struct button_params_s {
    char *name;
    sfVector2f pos;
    sfVector2f size;
    sfColor color;
    sfColor hoverColor;
    text_infos_t *text;
    char *linkedMenuName;
    button_func_t action;
}button_params_t;

int create_button(button_params_t buttonParams, rpg_t *params);
void handle_hover_and_click(button_node_t *buttonNode, sfVector2i mousePos,
    rpg_t *params);

//texts
typedef struct text_infos_s {
    char *text;
    sfFont *font;
    sfVector2f pos;
    sfColor color;
    int size;
}text_infos_t;
#endif
