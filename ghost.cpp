#include "headers/globals.h"
#include "headers/gameobject.h"
#include "headers/sprite.h"
#include "headers/ghost.h"
#include <random>
#include <iostream>

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
    if((clock.getElapsedTime() - starting_time).asSeconds() > 5)
    {
        is_blue = 0;
        set_color();
    }
    int tempx  = pos.x;
    int tempy  = pos.y;


    GameObject* pacman;
    for(auto character: characters)
    {
        if (character-> name == "Pacman")
        {
            pacman = character;
        }
    }


    int goal_pos_x, goal_pos_y;

    if(is_blue)
    {
        goal_pos_x = scatter_x;
        goal_pos_y = scatter_y;
    }
    else
    {
        goal_pos_x = pacman->pos.x + x_offset;
        goal_pos_y = pacman->pos.y + y_offset;
    }

 
    can_move_left = (map->is_not_edge(map, pos.x - 1, pos.y) && not_in_recent(position{pos.x - 1, pos.y}));
    can_move_up = (map->is_not_edge(map, pos.x, pos.y - 1) && not_in_recent(position{pos.x, pos.y - 1}));
    can_move_right = (map->is_not_edge(map, pos.x + 1, pos.y) && not_in_recent(position{pos.x + 1, pos.y}));
    can_move_down = (map->is_not_edge(map, pos.x, pos.y + 1) && not_in_recent(position{pos.x, pos.y + 1}));

    // std::cout << "\n";


    //std::cout << can_move_left << ' ' << can_move_up << ' ' << can_move_right << ' ' << can_move_down << "\n";
    if(!has_moved)
    {

        if(pos.y > goal_pos_y && can_move_up)
        {
                pos.y--;
        }

        else if(pos.y < goal_pos_y && can_move_down)
        {
                pos.y++;
        }

        else if(pos.x > goal_pos_x && can_move_left)
        {
                pos.x--;
        }

        else if(pos.x < goal_pos_x && can_move_right)
        {
                pos.x++;
        }

        else
        {
            if(can_move_up)
            {
                pos.y--;
            }
            else if(can_move_down)
            {
                pos.y++;
            }
            else if(can_move_left)
            { 
                pos.x--;
            }
            else if (can_move_right)
            {
                pos.x++;
            }
        }
        has_moved = 1;

        if (!(position{tempx, tempy} == position{pos.x, pos.y}))
        {
            recent_positions.push_back(position {pos.x, pos.y});
        }
        

        if(recent_positions.size() == 6)
        {
            recent_positions.erase(recent_positions.begin());
        }
        // int i = 0;
        // for(auto tmp_pos : recent_positions)
        // {
        //     std::cout << i << ' ' << tmp_pos.x << ' ' << tmp_pos.y << "\n";
        //     i++;
        // }
    }
 

    if(pos.x == -1 && pos.y == 12)
    {
        pos.x = 24;
    }

    else if(pos.x == 25 && pos.y == 12)
    {
        pos.x = 0;
    }
    update(map, tempx, tempy);
}


void Ghost::update()
{
    to_draw.setPosition(20 * pos.x, 20 * pos.y);
}


void Ghost::update(Map *map, int tempx, int tempy)
{
    for (auto obj:map->map[pos.y][pos.x].get_current_objs())
    {
        if (obj)
        {
            if (obj->name == "Pacman")
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

    starting_time = clock.restart();
}

void Ghost::set_color()
{
    switch (ghost_num)
    {
    case 1:
       {
           to_draw.setFillColor(sf::Color::Red);
           x_offset = 0;
           y_offset = 0;
           scatter_x = 1;
           scatter_y = 1;
       }
       break;

    case 2:
       {
           to_draw.setFillColor(sf::Color::Cyan);
           x_offset = 2;
           y_offset = 0;
           scatter_x = 23;
           scatter_y = 1;
       }
       break;

    case 3:
       {
           to_draw.setFillColor(sf::Color::Magenta);
           x_offset = 0;
           y_offset = 2;
           scatter_x = 1;
           scatter_y = 23;
       }
       break;

    case 4:
       {
           to_draw.setFillColor(sf::Color::Green);
           x_offset = -2;
           y_offset = 0;
           scatter_x = 23;
           scatter_y = 23;
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

bool Ghost::not_in_recent(position test_pos)
{
    for (auto pos: recent_positions)
    {
        if(test_pos == pos)
        {
            return false;
        }
    }
    return true;
} 