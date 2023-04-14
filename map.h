#ifndef MAP_H
#define MAP_H

#include "node.h"

class Map
{
    std::vector<std::vector<Node> > map;

    Map(std::vector<std::vector<Node> >);
    ~Map();
};

#endif
