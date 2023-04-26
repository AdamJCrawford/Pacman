#include <SFML/Graphics.hpp>
#include "headers/gameobject.h"
#include "headers/edge.h"


Edge::Edge(int x, int y)
{
    to_draw.setRadius(10.f);
    to_draw.setFillColor(sf::Color::Blue);

    name = "Edge";
    position tmp_pos;

    tmp_pos.x = x;
    tmp_pos.y = y;
    pos       = tmp_pos;
    update();
}


void Edge::update()
{
    to_draw.setPosition(20 * pos.x, 20 * pos.y);
}


sf::CircleShape Edge::draw()
{
    return to_draw;
}
