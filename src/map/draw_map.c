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
    sfRenderWindow_setView(main->window->renderWindow, main->view);
}

void draw_layer(sfRenderWindow *window, layer_t *layer, render_bounds_t bounds)
{
    for (int i = bounds.startRow; i < bounds.endRow; i++)
        for (int j = bounds.startCol; j < bounds.endCol; j++)
            sfRenderWindow_drawSprite(window, layer->tiles[i][j], NULL);
}

render_bounds_t set_render_boundaries(int tileSize, sfVector2f *viewSize,
    sfVector2f *viewCenter, map_t *map)
{
    int startRow = (int)(viewCenter->y - viewSize->y / 2) / tileSize;
    int endRow = (int)(viewCenter->y + viewSize->y / 2) / tileSize + 1;
    int startCol = (int)(viewCenter->x - viewSize->x / 2) / tileSize;
    int endCol = (int)(viewCenter->x + viewSize->x / 2) / tileSize + 1;

    startRow = startRow < 0 ? 0 : startRow;
    endRow = endRow > map->height ? map->height : endRow;
    startCol = startCol < 0 ? 0 : startCol;
    endCol = endCol > map->width ? map->width : endCol;
    return (render_bounds_t){startRow, endRow, startCol, endCol};
}

void draw_map(rpg_t *main, map_t *map)
{
    int tileSize = 16;
    render_bounds_t bounds;
    sfVector2f viewSize;
    sfVector2f viewCenter;

    if (!main || !map)
        return;
    viewSize = sfView_getSize(main->view);
    viewCenter = sfView_getCenter(main->view);
    bounds = set_render_boundaries(tileSize, &viewSize, &viewCenter, map);
    for (int l = 0; l < map->layer_count - 1; l++)
        draw_layer(main->window->renderWindow, map->layers[l], bounds);
    entities_displayer(main);
    draw_layer(main->window->renderWindow,
        map->layers[map->layer_count - 1], bounds);
}
