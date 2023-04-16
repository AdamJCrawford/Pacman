#include "headers/food.h"
#include "headers/cookie.h"



Cookie::Cookie()
{
    score_given_when_eaten = 10;

    to_draw.setRadius(10.f);
    to_draw.setFillColor(sf::Color::White);
    name = "Cookie";
}


Cookie::Cookie(sf::CircleShape tmp_to_draw)
{
    score_given_when_eaten = 10;
    to_draw = tmp_to_draw;
    name    = "Cookie";
}


void Cookie::update()
{
    to_draw.setPosition(pos.x, pos.y);
}


sf::CircleShape Cookie::draw()
{
    return to_draw;
}
