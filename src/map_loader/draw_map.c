/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** draw_map.c
*/

#include "rpg.h"

void set_view(rpg_t *main, entity_t *player)
{
    sfVector2f center = {player->pos.x, player->pos.y};
    sfVector2f size = {main->window->mode.width / 3,
    main->window->mode.height / 3};

    sfView_setCenter(main->view, center);
    sfView_setSize(main->view, size);
    sfRenderWindow_setView(main->window->renderWindow, main->view);
}

void draw_layer(sfRenderWindow *window, layer_t *layer)
{
    for (int i = 0; i < layer->height; i++)
        for (int j = 0; j < layer->width; j++)
            sfRenderWindow_drawSprite(window, layer->tiles[i][j], NULL);
}

void draw_map(rpg_t *main, map_t *map)
{
    entity_t *player = NULL;

    if (!main || !map)
        return;
    player = find_entity(main, "player");
    if (!player)
        return;
    set_view(main, player);
    for (int l = 0; l < map->layer_count; l++)
        draw_layer(main->window->renderWindow, map->layers[l]);
}
