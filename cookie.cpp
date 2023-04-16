#include <SFML/Graphics.hpp>
#include <string>
#include "headers/cookie.h"



Cookie::Cookie(int x, int y)
{
    name = "Cookie";
    score_given_when_eaten = 10;

    to_draw.setRadius(10.f);
    to_draw.setFillColor(sf::Color::White);

    pos.x = x;
    pos.y = y;
    update();
}


void Cookie::update()
{
    to_draw.setPosition(pos.x, pos.y);
}


sf::CircleShape Cookie::draw()
{
    return to_draw;
}
