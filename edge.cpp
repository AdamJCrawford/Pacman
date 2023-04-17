#include <SFML/Graphics.hpp>
#include "headers/gameobject.h"
#include "headers/edge.h"

Edge::Edge()
{
    to_draw.setRadius(10.f);
    to_draw.setFillColor(sf::Color::Blue);
    name = "Edge";
}


Edge::Edge(int x, int y)
{
    Edge();
    position tmp_pos;

    tmp_pos.x = x;
    tmp_pos.y = y;
    pos       = tmp_pos;
    update();
}


void Edge::update()
{
    to_draw.setPosition(pos.x, pos.y);
}


sf::CircleShape Edge::draw()
{
    return to_draw;
}
