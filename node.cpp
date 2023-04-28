#include "headers/gameobject.h"
#include "headers/node.h"
#include <vector>

Node::Node(position tmp_pos, GameObject *tmp_current_obj = nullptr)
{
    pos          = tmp_pos;
    current_objs = { tmp_current_obj };
}


Node::Node(int x, int y, GameObject *tmp_current_obj = nullptr)
{
    position tmp_pos = { x, y };

    pos          = tmp_pos;
    current_objs = { tmp_current_obj };
}


Node::~Node()
{
    for (int i = 0; i < current_objs.size(); i++)
    {
        current_objs[i] = nullptr;
        delete current_objs[i];
    }
}


position Node::get_pos()
{
    return pos;
}


std::vector<GameObject *> Node::get_current_objs()
{
    return current_objs;
}


void Node::add_object(GameObject *temp_obj)
{
    current_objs.push_back(temp_obj);
}


void Node::del_object(GameObject *temp)
{
    current_objs.erase(std::remove(current_objs.begin(), current_objs.end(), temp), current_objs.end());
}