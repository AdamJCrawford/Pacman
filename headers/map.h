#ifndef MAP_H
#define MAP_H

#include <string>
#include "node.h"

class Map {
public:
    std::vector<std::string> string_map;
    std::vector<std::vector<Node> > map;

    Map();

    void create_map();
};

#endif
