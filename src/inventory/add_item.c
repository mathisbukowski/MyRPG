/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** add_item.c
*/

#include "rpg.h"

int add_item(rpg_t *main, char *name, int nb)
{
    int x = find_id(name);
    char *value;

    if (x < 0)
        return 1;
    value = get_value_item(x);
    if (item_bank[x].quantity + nb < 10000) {
        item_bank[x].quantity += nb;
        sfText_setString(item_bank[x].texte, value);
        free(value);
        return 0;
    }
    free(value);
    return 1;
}
