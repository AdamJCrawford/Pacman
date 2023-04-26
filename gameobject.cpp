#include <SFML/Graphics.hpp>
#include "headers/gameobject.h"


position GameObject::get_position()
{
    return pos;
}


void GameObject::set_position(position tmp_pos)
{
    pos = tmp_pos;
}


void GameObject::set_position(int x, int y)
{
    position tmp_pos;

    tmp_pos.x = x;
    tmp_pos.y = y;

    pos = tmp_pos;
}


std::string GameObject::get_name()
{
    return name;
}


void GameObject::set_name(std::string tmp_name)
{
    name = tmp_name;
}


sf::CircleShape GameObject::draw()
{
    return sf::CircleShape();
}
