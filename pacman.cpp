#include "headers/gameobject.h"
#include "headers/sprite.h"
#include "headers/pacman.h"
#include <iostream>
Pacman::Pacman(int x, int y)
{
    to_draw.setRadius(10.f);
    to_draw.setFillColor(sf::Color::Yellow);
    name = "Pacman";
    position tmp_pos;

    tmp_pos.x = x;
    tmp_pos.y = y;
    pos       = tmp_pos;
    update();
}


void Pacman::move(void ( *f )(int, int, int, int))
{
    int tempx = pos.x;
    int tempy = pos.y;

    switch (curr_key)
    {
    case 1:
       {
           pos.y++;
           break;
       }

    case 2:
       {
           pos.x--;
           break;
       }

    case 3:
       {
           pos.y--;
           break;
       }

    case 4:
       {
           pos.x++;
           break;
       }

    default:
        break;
    }
    update(f, tempx, tempy);
}


void Pacman::update()
{
    to_draw.setPosition(20 * pos.x, 20 * pos.y);
}


void Pacman::update(Map *map, int tempx, int tempy)
{
    // map.f(tempy, tempx, pos.x, pos.y);
    to_draw.setPosition(20 * pos.x, 20 * pos.y);
}


sf::CircleShape Pacman::draw()
{
    return to_draw;
}
