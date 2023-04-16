#include "headers/gameobject.h"
#include "headers/node.h"

Node::Node(position tmp_pos, GameObject *tmp_current_obj = nullptr)
{
    pos         = tmp_pos;
    current_obj = tmp_current_obj;
}


Node::Node(int x, int y, GameObject *tmp_current_obj = nullptr)
{
    position tmp_pos = { x, y };

    pos         = tmp_pos;
    current_obj = tmp_current_obj;
}


Node::~Node()
{
    delete current_obj;
}


position Node::get_pos()
{
    return pos;
}


GameObject *Node::get_current_obj()
{
    return current_obj;
}
