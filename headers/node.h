#ifndef NODE_H
#define NODE_H


class Node {
    position pos;
    GameObject *current_obj;
public:
    Node(position, GameObject *);
    Node(int, int, GameObject *);
    ~Node();

    position get_pos();
    GameObject *get_current_obj();
};

#endif
