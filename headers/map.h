#ifndef MAP_H
#define MAP_H

class Map {
public:
    std::vector<std::string> string_map;
    std::vector<std::vector<Node> > map;

    Map();

    void create_map();
};

#endif
