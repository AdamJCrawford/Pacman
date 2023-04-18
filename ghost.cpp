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
    position tmp_pos;

    tmp_pos.x = x;
    tmp_pos.y = y;
    pos       = tmp_pos;
    update();
}

void Ghost::move()
{
    int random = (rand() % 4);
    switch(random)
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
    
    update();
}

void Ghost::update()
{
    to_draw.setPosition(20 * pos.x, 20 * pos.y);
}


sf::CircleShape Ghost::draw()
{
    return to_draw;
}
 