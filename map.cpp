#include <vector>
#include <iostream>

#include "headers/globals.h"
#include "headers/gameobject.h"
#include "headers/node.h"
#include "headers/map.h"
#include "headers/edge.h"
#include "headers/food.h"
#include "headers/cookie.h"
#include "headers/pacdot.h"
#include "headers/sprite.h"
#include "headers/ghost.h"
#include "headers/pacman.h"

Map::Map()
{
    string_map = {
        "#########################", // 0
        "#o.....................o#", // 1
        "#.##.#.####.#.####.#.##.#", // 2
        "#.##.#..#...#...##.#.##.#", // 3
        "#....##.#.#####.#..#....#", // 4
        "#.#####.#.#...#.#.#####.#", // 5
        "#.#.....#.#.#.#.#.......#", // 6
        "#.#.##.##.#.#.#.###.###.#", // 7
        "#......##   #   ###.#...#", // 8
        "#.####..  #####  ...#.#.#", // 9
        "#.......#   1   ###.....#", // 10
        "###.###.#  234  #...#.###", // 11
        " .......#       #.#..... ", // 12
        "###.#.#.# ##### #.#.#.###", // 13
        "#...#.#.#       #.#.#...#", // 14
        "#.###.#.# ##### #.#.###.#", // 15
        "#.....#.    #    .#.....#", // 16
        "#.###.#.#.#.#.#.#.#.###.#", // 17
        "#.......#.#.#.#.#.......#", // 18
        "#.#####.#.#...#.#.#####.#", // 19
        "#....##.#.#####.#.##....#", // 20
        "#.##.#..#.......#..#.##.#", // 21
        "#.##.#.####.#.####.#.##.#", // 22
        "#o..........p..........o#", // 23
        "#########################"  // 24
        
    };
}


void Map::create_map()
{
    for (int j = 0; j < 25; j++)
    {
        std::vector<Node> tmp_row;
        for (int i = 0; i < 25; i++)
        {
            switch (string_map[j][i])
            {
            case '#':
               {
                   Edge *tmp_edge = new Edge(i, j);
                   tmp_row.push_back(Node(i, j, tmp_edge));
               }
               break;

            case ' ':
               {
                   tmp_row.push_back(Node(i, j, nullptr));
               }
               break;

            case '.':
               {
                   Cookie *tmp_cookie = new Cookie(i, j);
                   tmp_row.push_back(Node(i, j, tmp_cookie));
               }
               break;

            case 'o':
               {
                   Pacdot *tmp_pacdot = new Pacdot(i, j);
                   tmp_row.push_back(Node(i, j, tmp_pacdot));
               }
               break;

            case 'p':
               {
                   Pacman *tmp_pacman = new Pacman(i, j);
                   tmp_row.push_back(Node(i, j, tmp_pacman));
               }
               break;

            case '1':
               {
                   Ghost *tmp_ghost = new Ghost(i, j, 1);
                   tmp_row.push_back(Node(i, j, tmp_ghost));
               }
               break;

            case '2':
               {
                   Ghost *tmp_ghost = new Ghost(i, j, 2);
                   tmp_row.push_back(Node(i, j, tmp_ghost));
               }
               break;

            case '3':
               {
                   Ghost *tmp_ghost = new Ghost(i, j, 3);
                   tmp_row.push_back(Node(i, j, tmp_ghost));
               }
               break;

            case '4':
               {
                   Ghost *tmp_ghost = new Ghost(i, j, 4);
                   tmp_row.push_back(Node(i, j, tmp_ghost));
               }
               break;

            case '-':
               {
                   Edge *tmp_gate = new Edge(i, j);
                   tmp_row.push_back(Node(i, j, tmp_gate));
               }
               break;

            default:
               {
                   std::cout << "default reached" << std::endl;
                   break;
               }
            }
        }
        map.push_back(tmp_row);
    }
}

bool Map::is_not_edge(Map *map, int x, int y) {
    // std::cout << x << ' ' << y << "\n";
    //last coordinate is 12, 23
    if (x >= 0 && x < map_width && y >= 0 && y < map_length)
    {
        for (auto obj: map->map[y][x].get_current_objs())
        {
            if (obj)
            {
                if (obj->name == "Edge")
                {
                    return false;
                }
            }
        }
    }
    return true;
}

void Map::print_map()
{
    for(auto row :map)
    {
        for (auto node: row)
        {
            for(auto item: node.get_current_objs())
            {
                if(item)
                {
                    if(item->name == "Edge")
                    {
                        std::cout << "#";
                    }
                    else if(item->name == "Cookie")
                    {
                        std::cout << ".";
                    }
                    else if(item->name == "Pacman")
                    {
                        std::cout << "P";
                    }
                    else if(item->name == "Ghost")
                    {
                        std::cout << "1";
                    }
                    else if(item->name == "Pacdot")
                    {
                        std::cout << "o";
                    }
                }
                else
                {
                    std::cout << ' ';
                }
            }
            std::cout << ' ';
        }
        std::cout << "\n";
    }
}  