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


void Pacman::move(Map* map)
{
    int tempx = pos.x;
    int tempy = pos.y;

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
    update(map, tempx, tempy);
}


void Pacman::update()
{
    to_draw.setPosition(20 * pos.x, 20 * pos.y);
}

 
void Pacman::update(Map *map, int tempx, int tempy)
{
    // map.f(tempy, tempx, pos.x, pos.y);
    std::cout << curr_key << "\n";
    for(auto obj:map->map[pos.y][pos.x].get_current_objs())
    {
        if (obj)
        {
            if(obj->name == "Edge")
            {
                pos.x = tempx;
                pos.y = tempy;
            }
            else if(obj->name == "Ghost")
            {
                std::exit(0);
            }
            else if(obj->name == "Cookie")
            {
                score+= 10;
                map->map[pos.y][pos.x].add_object(this);
                // Need to delete cookie
                //map->map[tempy][tempx].del_object(this);
                map->map[tempy][tempx].del_object(this);
            }
            else if(obj->name == "Pacdot")
            {
                score+= 50;
                map->map[pos.y][pos.x].add_object(this);
                map->map[tempy][tempx].del_object(this);
            }
        }   
    update();
    }
}


sf::CircleShape Pacman::draw()
{
    return to_draw;
}
   