#ifndef NODE_H
#define NODE_H

#include <vector>

class Node {
    position pos;
    std::vector<GameObject *> current_objs;
public:
    Node(position, GameObject *);
    Node(int, int, GameObject *);
    ~Node();

    position get_pos();
    std::vector<GameObject *> get_current_objs();
    void add_object(GameObject *);
    void del_object(GameObject *);
};

#endif
