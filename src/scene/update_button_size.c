/*
** EPITECH PROJECT, 2024
** myrpg
** File description:
** update_button_size.c
*/

#include "rpg.h"

void update_button_positions_and_sizes(rpg_t *main, scene_t *scene)
{
    button_node_t *button = scene->menus->menu->buttons;
    sfVector2u window_size = sfRenderWindow_getSize(
        main->window->renderWindow);
    sfVector2f new_position;
    sfVector2f new_size;

    while (button != NULL) {
        new_position.x = button->button->pos.x * window_size.x /
            main->window->mode.width / 1.5;
        new_position.y = button->button->pos.y * window_size.y /
            main->window->mode.height / 1.5;
        new_size.x = sfRectangleShape_getSize(button->button->rect).x *
            window_size.x / main->window->mode.width;
        new_size.y = sfRectangleShape_getSize(button->button->rect).y *
            window_size.y / main->window->mode.height;
        sfRectangleShape_setPosition(button->button->rect, new_position);
        sfRectangleShape_setSize(button->button->rect, new_size);
        sfText_setPosition(button->button->text, new_position);
        button = button->next;
    }
}
