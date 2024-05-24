/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** move_entity.c
*/

#include "rpg.h"

void move_entity(rpg_t *main, entity_t *entity, int direction)
{
    float speed = entity->speed;

    if ((sfKeyboard_isKeyPressed(sfKeyZ) || sfKeyboard_isKeyPressed(sfKeyS)) &&
        (sfKeyboard_isKeyPressed(sfKeyQ) || sfKeyboard_isKeyPressed(sfKeyD))) {
        speed /= sqrt(2);
    }
    if (direction == UP) {
        if (entity->pos.y - speed)
        entity->pos.y -= speed;
    }
    if (direction == DOWN) {
        entity->pos.y += speed;
    }
    if (direction == LEFT) {
        entity->pos.x -= speed;
    }
    if (direction == RIGHT) {
        entity->pos.x += speed;
    }
}
