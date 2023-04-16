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
        "#########################", // 1
        "#o.....................o#", // 2
        "#.##.#.####.#.####.#.##.#", // 3
        "#.##.#..#...#...##.#.##.#", // 4
        "#....##.#.#####.#..#....#", // 5
        "#.#####.#.#...#.#.#####.#", // 6
        "#.#.....#.#.#.#.#.......#", // 7
        "#.#.##.##.#.#.#.###.###.#", // 8
        "#......##   #   ###.#...#", // 9
        "#.####..  #####  ...#.#.#", // 10
        "#.......#   1   ###.....#", // 11
        "###.###.# ##-## #...#.###", // 12
        " .......# #234# #.#..... ", // 13
        "###.#.#.# ##### #.#.#.###", // 14
        "#...#.#.#       #.#.#...#", // 15
        "#.###.#.# ##### #.#.###.#"  // 16
        "#.....#.    #    .#.....#", // 17
        "#.###.#.#.#.#.#.#.#.###.#", // 18
        "#.......#.#.#.#.#.......#", // 19
        "#.#####.#.#...#.#.#####.#", // 20
        "#....##.#.#####.#.##....#", // 21
        "#.##.#..#.......#..#.##.#", // 22
        "#.##.#.####.#.####.#.##.#", // 23
        "#o..........p..........o#", // 24
        "#########################"  // 25
    };
}


void Map::create_map()
{

    for (int i = 0; i < 24; i++)
    {
        std::vector<Node> tmp_row;
        for (int j = 0; j < 25; j++)
        {
            switch (string_map[i][j])
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
