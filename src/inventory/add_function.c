/*
** EPITECH PROJECT, 2024
** rpg_dev
** File description:
** add_function.c
*/
#include "rpg.h"

void add_in_inventory(rpg_t *main, int y, int x, int i)
{
    main->inventory->slot[y][x] = item_bank[i];
}

void add_inventory_select(rpg_t *main, int y, int x, char *name)
{
    for (int i = 0; item_bank[i].id != 0; i ++) {
        if (my_strcmp(item_bank[i].name, name) == 0) {
            add_in_inventory(main, y, x, i);
            return;
        }
    }
}

static int second_loop_empty(int i, rpg_t *main, int *y, int *x)
{
    for (int j = 0; j < 5; j++) {
        if (main->inventory->slot[i][j].id == 0) {
            *x = j;
            *y = i;
            return 0;
        }
    }
    return 1;
}

static void find_empty(rpg_t *main, int *y, int *x)
{
    for (int i = 0; i < 5; i++) {
        if (second_loop_empty(i, main, y, x) == 0)
            return;
    }
}

void auto_add_inventory(rpg_t *main, char *name)
{
    int x = 0;
    int y = 0;

    find_empty(main, &y, &x);
    for (int i = 0; item_bank[i].id != 0; i ++) {
        if (my_strcmp(item_bank[i].name, name) == 0) {
            add_in_inventory(main, y, x, i);
            return;
        }
    }
}
