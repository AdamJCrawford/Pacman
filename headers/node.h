#ifndef NODE_H
#define NODE_H

struct position
{
    int x; // Row
    int y; // Col
};

class Node {
public:
    position pos;
    Node(position tmp_pos);
    Node(int x, int y);
};

#endif
