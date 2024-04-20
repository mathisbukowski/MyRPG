/*
** EPITECH PROJECT, 2023
** bsmypaint
** File description:
** my_paint.h
*/

#ifndef MYPAINT_H
    #define MYPAINT_H
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>

// Enum for Tools
typedef enum tools_s {
    PENCIL,
    ERASER
} tools_t;

// Enum for button statuses
typedef enum button_status_s {
    NONE,
    HOVER,
    PRESSED
} button_status_t;

// Button structure
typedef struct button_s {
    sfRectangleShape *rect;
    sfVector2f size;
    sfVector2f position;
    button_status_t status;
    sfColor color;
    sfText *text;
    sfBool is_clicked;
    sfBool is_in_menu;
    sfSprite *icon;
    sfTexture *sprite_text;
    char *id;
    int index;
} button_t;

// Linked list for button managers
typedef struct butlist_s {
    button_t button;
    struct butlist_s *next;
} butlist_t;

// Menu structure
typedef struct menu_s {
    sfRectangleShape *background;
    sfText **items;
    int itemCount;
    sfBool isOpen;
    sfFont *font;
    sfVector2f pos;
    sfVector2f size;
    sfText *text;
} menu_t;

// Linked list for menu managers
typedef struct menulist_s {
    menu_t menu;
    struct menulist_s *next;
} menulist_t;

// Color structure
typedef struct color_s {
    sfColor color;
    char *name;
} color_t;

// Palette structure
typedef struct palette_s {
    color_t color;
    struct palette_s *next;
} palette_t;

// Board Structure
typedef struct board_s {
    sfImage *board;
    sfSprite *sprite_board;
    sfTexture *text_board;
    sfVector2i dim;
    sfVector2f position;
    sfColor penColor;
    int penSize;
    int erSize;
    tools_t tool;
} board_t;

// SlideBar Structure
typedef struct slide_s {
    sfRectangleShape *slideBg;
    sfRectangleShape *slideHandle;
    sfRectangleShape *eraserBg;
    sfRectangleShape *eraseHandle;
} slide_t;

// Global Structure
typedef struct paint_s {
    sfRenderWindow *window;
    sfFont *font;
    sfSprite *logo_sprite;
    palette_t *palette;
    butlist_t *buttonList;
    menulist_t *menuList;
    sfImage *icon;
    board_t *board;
    slide_t *slide;
} paint_t;

// Function prototypes
int paint_loop(char *file);
paint_t *init_structure(paint_t *main);
int check_extension(char *file);
void push_events(paint_t *main);
void update_style(paint_t *main, butlist_t **head);

// Menu Functions
void create_menu(paint_t *main,
    sfVector2f pos, sfVector2f size, char *text);
void destroy_menu(menulist_t **list);
void new_menu(paint_t *main);
void display_menu(paint_t *main);
int is_clicked_menu(paint_t *main);

// Buttons Functions
int is_clicked(paint_t *main);
void create_button(paint_t *main, sfVector2f pos,
    color_t color, sfVector2f size);
void destroy_button(butlist_t **list);
void button_displayer(butlist_t **head, sfRenderWindow *main);
void deploy_buttons(paint_t *main);
void create_but_with_text(paint_t *main, sfVector2f pos,
    sfColor color, char *text);
void create_button_with_icon(paint_t *main, sfVector2f pos,
    sfColor color, char *imagePath);
void create_but_menu(paint_t *main, sfVector2f pos, sfColor color, char *text);

// Colors Functions
void create_color(paint_t *main, sfColor newColor, char *name);
void destroy_color(palette_t **list);
void color_to_button(paint_t *main, palette_t **head);
void deploy_colors(paint_t *main);

// Board Functions
void init_board(paint_t *main);
void draw_on_board(paint_t *main);

// Slider Menu
void create_slidebar(paint_t *main);
void destroy_slide(paint_t *main);

// Eraser Function
void upsize_eraser(paint_t *main, sfEvent event);

// help
void display_help(paint_t *main);
void remove_help(paint_t *main);
void display_about(paint_t *main);
void remove_about(paint_t *main);

#endif //MYPAINT_H
