#ifndef NODE_H
#define NODE_H

struct position
{
    int x; // Row
    int y; // Col
};

class Node {
    position pos;

    Node(position tmp_pos);
    Node(int x, int y);
    ~Node();
};

#endif
