#include "headers/gameobject.h"
#include "headers/sprite.h"
#include "headers/map.h"
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


void Pacman::move(Map *map)
{
    int tempx = pos.x;
    int tempy = pos.y;

    if (has_moved)
    {
        return;
    }

    switch (curr_key)
    {
    case 1:
       {
           pos.y--;
           break;
       }

    case 2:
       {
           pos.x--;
           break;
       }

    case 3:
       {
           pos.y++;
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
    has_moved = 1;
    update(map, tempx, tempy);
}


void Pacman::update()
{
    to_draw.setPosition(20 * pos.x, 20 * pos.y);
}


void Pacman::update(Map *map, int tempx, int tempy)
{
    // map.f(tempy, tempx, pos.x, pos.y);
    for (auto obj:map->map[pos.y][pos.x].get_current_objs())
    {
        if (obj)
        {
            if (obj->name == "Edge")
            {
                pos.x = tempx;
                pos.y = tempy;
            }
            else if (obj->name == "Ghost")
            {
                std::exit(0);
            }
            else if (obj->name == "Cookie")
            {
                score += 10;
                map->map[pos.y][pos.x].del_object(obj);
            }
            else if (obj->name == "Pacdot")
            {
                score += 50;
                map->map[pos.y][pos.x].del_object(obj);
            }
        }
    }
    map->map[tempy][tempx].del_object(this);
    map->map[pos.y][pos.x].add_object(this);
    update();
}


sf::CircleShape Pacman::draw()
{
    return to_draw;
}


void Pacman::reset()
{
    has_moved = 0;
}
