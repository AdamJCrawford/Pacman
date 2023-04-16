#include "headers/food.h"
#include "headers/pacdot.h"



Pacdot::Pacdot()
{
    score_given_when_eaten = 50;

    to_draw.setRadius(20.f);
    to_draw.setFillColor(sf::Color::White);
    name = "Pacdot";
}


Pacdot::Pacdot(int x, int y)
{
    score_given_when_eaten = 50;

    to_draw.setRadius(20.f);
    to_draw.setFillColor(sf::Color::White);
    name  = "Pacdot";
    pos.x = x;
    pos.y = y;
    update();
}


Pacdot::Pacdot(sf::CircleShape tmp_to_draw)
{
    score_given_when_eaten = 50;
    to_draw = tmp_to_draw;
    name    = "Pacdot";
}


void Pacdot::update()
{
    to_draw.setPosition(pos.x, pos.y);
}


sf::CircleShape Pacdot::draw()
{
    return to_draw;
}
