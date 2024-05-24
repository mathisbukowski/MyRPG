/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** move_entity.c
*/

#include "rpg.h"

static void handle_diagonal_movement(rpg_t *main, entity_t *entity,
    float *speed)
{
    if ((sfKeyboard_isKeyPressed(sfKeyZ) || sfKeyboard_isKeyPressed(sfKeyS)) &&
        (sfKeyboard_isKeyPressed(sfKeyQ) || sfKeyboard_isKeyPressed(sfKeyD))) {
        (*speed) /= sqrt(2);
    }
}

void move_entity(rpg_t *main, entity_t *entity, int direction)
{
    float speed = entity->speed;
    sfVector2f next_pos = entity->pos;
    int tile_x;
    int tile_y;

    handle_diagonal_movement(main, entity, &speed);
    if (direction == UP)
        next_pos.y -= speed;
    if (direction == DOWN)
        next_pos.y += speed;
    if (direction == LEFT)
        next_pos.x -= speed;
    if (direction == RIGHT)
        next_pos.x += speed;
    tile_x = next_pos.x / 16;
    tile_y = next_pos.y / 16;
    if (main->collisions_map->layers[0]->coords[tile_y + 1][tile_x].data ==
        NON_COLIDE_TILE)
        entity->pos = next_pos;
}
