/*
** EPITECH PROJECT, 2020
** snake_sfml
** File description:
** ai.c++
*/

#include "../include/all_includes.h"

bool next_self_col(Game *go, char dir)
{
    std::list<parts_t>::iterator cur;
    cur = go->my_snake.parts.begin();
    sf::Vector2f pos = cur->pos;

    switch (dir) {
        case 'R':
            pos.x += 64;
            break;
        case 'L':
            pos.x -= 64;
            break;
        case 'U':
            pos.y -= 64;
            break;
        case 'D':
            pos.y += 64;
            break;
        default:
            break;
    }
    for (; cur != --go->my_snake.parts.end(); cur++) {
        if (cur->pos == pos)
            return true;
    }
    return false;
}

bool get_item(Game *game)
{
    sf::Vector2f pos = game->item.getPosition();
    std::list<parts_t>::iterator cur;
    cur = game->my_snake.parts.begin();
    if (cur->pos.x < pos.x && cur->pos.y == pos.y && cur->dir % 2 == 0
    && next_self_col(game, 'R'))
        game->my_snake.turn_right();
    else if (cur->pos.x > pos.x && cur->pos.y == pos.y && cur->dir % 2 == 0
    && next_self_col(game, 'L'))
        game->my_snake.turn_left();
    else if (cur->pos.x == pos.x && cur->pos.y > pos.y && cur->dir % 2 == 1
    && next_self_col(game, 'U'))
        game->my_snake.turn_up();
    else if (cur->pos.x == pos.x && cur->pos.y < pos.y && cur->dir % 2 == 1
    && next_self_col(game, 'D'))
        game->my_snake.turn_down();
    else
        return false;
    return true;
}