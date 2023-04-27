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


// vector<position> Ghost::DFS()
// {



    // int starting_pos_x = pos.x;
    // int starting_pos_y = pos.y;



    // vector<Node*> current_path;

    // while front.size()
    // {
    //     current = front.pop_back();
    //     if(current-> name == "Pacman")
    //     {
    //         return current_path;
    //     }
    //     else
    //     {
    //         // need to check that these are valid locations
    //         front.push_back(map.map[current.pos.y][current.pos.x + 1]);
    //         front.push_back(map.map[current.pos.y - 1][current.pos.x]);
    //         front.push_back(map.map[current.pos.y][current.pos.x - 1]);
    //         front.push_back(map.map[current.pos.y + 1][current.pos.x]);
    //     }
    // }

// }

/*
def BFS(problem, repeat_check=False):
    current_node = Node(problem.start)
    front = Frontier(current_node)
    if repeat_check:
        reached = {}
    while not front.is_empty():
        current_node = front.pop()
        if problem.is_goal(current_node.loc):
            return current_node
        if repeat_check:
            if current_node in reached:
                continue
            reached[current_node] = 1
        front.add(current_node.expand(problem))
    return None
*/

void Ghost::move(Map *map)
{
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

    int goal_pos_x = pacman->pos.x;
    int goal_pos_y = pacman->pos.y;
    
    if(pos.x > goal_pos_x)
    {
        if(pos.x != 0 && !map->is_edge(map, pos.y, pos.x - 1))
        {
            pos.x--;
        }
    }
    else if(pos.x < goal_pos_y)
    {
        if(pos.x < map_width - 1 && !map->is_edge(map, pos.y, pos.x + 1))
        {
            pos.x++;
        }
    }

    if(pos.y > goal_pos_y && pos.y != 0)
    {
        if(!map->is_edge(map, pos.y - 1, pos.x))
        {
            pos.y--;
        }
    }
    else if(pos.y < goal_pos_y)
    {
        if(pos.y < map_width - 1 && !map->is_edge(map, pos.y + 1, pos.x))
        {
            pos.y++;
        }
    }

 
    // int random = (rand() % 4);

    // switch (random)
    // {
    // case 1:
    //    {
    //        pos.y++;
    //        break;
    //    }

    // case 2:
    //    {
    //        pos.x--;
    //        break;
    //    }

    // case 3:
    //    {
    //        pos.y--;
    //        break;
    //    }

    // case 4:
    //    {
    //        pos.x++;
    //        break;
    //    }
    // }

    if(pos.x == -1 && pos.y == 12)
    {
        pos.x = 24;
    }

    else if(pos.x == 25 && pos.y == 12)
    {
        pos.x = 0;
    }

    has_moved = 1;
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