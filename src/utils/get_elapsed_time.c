/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** get_elapsed_time.c
*/

#include "rpg.h"

float get_elapsed_time(rpg_t *main)
{
    sfTime time = sfClock_getElapsedTime(main->global);
    float seconds = time.microseconds / 1000000.0f;

    sfClock_restart(main->global);
    return seconds;
}
