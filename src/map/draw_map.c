/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** draw_map.c
*/

#include "rpg.h"

void set_view(rpg_t *main, entity_t *player)
{
    sfVector2f center;
    sfVector2f size = {(float)main->window->mode.width / 4.0f,
        (float)main->window->mode.height / 4.0f};

    center.x = player->pos.x;
    center.y = player->pos.y;
    sfView_setCenter(main->view, center);
    sfView_setSize(main->view, size);
    sfRenderWindow_setView(main->window->render_window, main->view);
}

void draw_layer(sfRenderWindow *window, layer_t *layer, render_bounds_t bounds)
{
    for (int i = bounds.start_row; i < bounds.end_row; i++)
        for (int j = bounds.start_col; j < bounds.end_col; j++)
            sfRenderWindow_drawSprite(window, layer->tiles[i][j], NULL);
}

render_bounds_t set_render_boundaries(int tile_size, sfVector2f *view_size,
    sfVector2f *view_center, map_t *map)
{
    int start_row = (int)(view_center->y - view_size->y / 2) / tile_size;
    int end_row = (int)(view_center->y + view_size->y / 2) / tile_size + 1;
    int start_col = (int)(view_center->x - view_size->x / 2) / tile_size;
    int end_col = (int)(view_center->x + view_size->x / 2) / tile_size + 1;

    start_row = start_row < 0 ? 0 : start_row;
    end_row = end_row > map->height ? map->height : end_row;
    start_col = start_col < 0 ? 0 : start_col;
    end_col = end_col > map->width ? map->width : end_col;
    return (render_bounds_t){start_row, end_row, start_col, end_col};
}

void draw_map(rpg_t *main, map_t *map)
{
    int tileSize = 16;
    render_bounds_t bounds;
    sfVector2f view_size;
    sfVector2f view_center;

    if (!main || !map)
        return;
    view_size = sfView_getSize(main->view);
    view_center = sfView_getCenter(main->view);
    bounds = set_render_boundaries(tileSize, &view_size, &view_center, map);
    for (int l = 0; l < map->layer_count - 1; l++)
        draw_layer(main->window->render_window, map->layers[l], bounds);
    entities_displayer(main);
    draw_layer(main->window->render_window,
        map->layers[map->layer_count - 1], bounds);
}
