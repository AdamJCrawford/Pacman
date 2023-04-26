#include <SFML/Graphics.hpp>
#include <string>
#include "headers/cookie.h"



Cookie::Cookie(int x, int y)
{
    name = "Cookie";
    score_given_when_eaten = 10;

    to_draw.setRadius(5.f);
    to_draw.setFillColor(sf::Color::White);

    pos.x = x;
    pos.y = y;
    update();
}


void Cookie::update()
{
    to_draw.setPosition(20 * pos.x + 5, 20 * pos.y + 5);
}


sf::CircleShape Cookie::draw()
{
    return to_draw;
}
