#include "headers/globals.h"
#include "headers/gameobject.h"
#include "headers/sprite.h"
#include "headers/ghost.h"
#include <random>


Ghost::Ghost(int x, int y, int tmp_ghost_num)
{
    ghost_num = tmp_ghost_num;
    to_draw.setRadius(10.f);
    name = "Ghost";
    set_color();
    position tmp_pos;

    tmp_pos.x = x;
    tmp_pos.y = y;
    pos  = tmp_pos;
    update();
}


void Ghost::move(Map *map)
{
    int tempx  = pos.x;
    int tempy  = pos.y;

    int random = (rand() % 4);

    switch (random)
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
    }

    if(pos.x == -1 && pos.y == 12)
    {
        pos.x = 24;
    }

    else if(pos.x == 25 && pos.y == 12)
    {
        pos.x = 0;
    }


    
>>>>>>> faa90e7f3dd681f7bc4ba2525e2117867a5b55ba
x, 20 * pos.y);
}


void Ghost::update(Map *map, int tempx, int tempy)
{
    for (auto obj:map->map[pos.y][pos.x].get_current_objs())
    {
        if (obj)
        {
            if (obj->name == "Edge")
            {
                pos.x = tempx;
                pos.y = tempy;
            }
            else if (obj->name == "Pacman")
            {
                if(is_blue)
                {
                    is_blue = 0;
                    pos.x = 12;
                    pos.y = 12;
                    set_color();
                }
                else
                {
                    std::exit(0);
                }
            }
        }
    }
    map->map[tempy][tempx].del_object(this);
    map->map[pos.y][pos.x].add_object(this);
    update();
}


sf::CircleShape Ghost::draw()
{
    return to_draw;
}


void Ghost::reset()
{
    has_moved = 0;
}

void Ghost::blue_mode()
{
    is_blue = 1;
    
    to_draw.setFillColor(sf::Color{0xFFA500FF});
}

void Ghost::set_color()
{
    switch (ghost_num)
    {
    case 1:
       {
           to_draw.setFillColor(sf::Color::Red);
       }
       break;

    case 2:
       {
           to_draw.setFillColor(sf::Color::Cyan);
       }
       break;

    case 3:
       {
           to_draw.setFillColor(sf::Color::Magenta);
       }
       break;

    case 4:
       {
           to_draw.setFillColor(sf::Color::Green);
           break;
       }
    }
}

int Ghost::get_score_when_eaten()
{
    return score_given_when_eaten;
}

bool Ghost::blue_status()
{
    return is_blue;
}