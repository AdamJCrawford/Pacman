#include "headers/gameobject.h"


GameObject::get_position()
{
    return position;
}

GameObject::set_position(position tmp_pos)
{
    pos = tmp_pos;
}

GameObject::get_name()
{
    return name;
}

GameObject::set_name(std::string tmp_name)
{
    name = tmp_name;
}
