/*
** EPITECH PROJECT, 2024
** rpg-dev
** File description:
** NPCs.c
*/

#include "rpg.h"

static void black_smith_action(rpg_t *main, entity_t *entity,
    sfIntRect interact_rect, entity_t *player)
{
    sfVector2f npc_pos = sfSprite_getPosition(entity->sprite);
    sfText *to_interact = sfText_create();
    sfFont *font = main->utils->font;

    if (sfIntRect_contains(&interact_rect, player->pos.x, player->pos.y)
    == sfTrue) {
        if (sfKeyboard_isKeyPressed(sfKeyE))
            sfText_setString(to_interact, "Find my sword\n    son !");
        else
            sfText_setString(to_interact,
                "Find my sword\n    son !\n(Press E to accept)");
        sfText_setFont(to_interact, font);
        sfText_setScale(to_interact, (sfVector2f){.2f, .2f});
        sfText_setOutlineColor(to_interact, sfBlack);
        sfText_setOutlineThickness(to_interact, 1);
        sfText_setPosition(to_interact, (sfVector2f){npc_pos.x + 20,
            npc_pos.y + 10});
        sfRenderWindow_drawText(main->window->renderWindow, to_interact, NULL);
    }
    sfText_destroy(to_interact);
}

void create_npc(rpg_t *main, char *name, sfVector2f pos,
    sfIntRect interact_rect)
{
    entity_t *npc;
    sfVector2u sprite_size;
    float center_x;
    float center_y;

    add_entity_to_list(main, (entity_params_t){name, pos, PLAYER},
        "assets/NPCs/black-smith.png", black_smith_action);
    npc = find_entity(main, name);
    sprite_size = sfTexture_getSize(npc->texture);
    center_x = pos.x + sprite_size.x / 2.0f;
    center_y = pos.y + sprite_size.y / 2.0f;
    interact_rect.left = center_x - interact_rect.width / 2;
    interact_rect.top = center_y - interact_rect.height / 2;
    npc->interact_rect = interact_rect;
}
