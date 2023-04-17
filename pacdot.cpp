#include "headers/food.h"
#include "headers/pacdot.h"

Pacdot::Pacdot()
{
    score_given_when_eaten = 10;

    to_draw.setRadius(10.f);
    to_draw.setFillColor(sf::Color::White);
    name = "Pacdot";
}


Pacdot::Pacdot(int x, int y)
{
    Pacdot();
    pos.x = x;
    pos.y = y;
    update();
}


void Pacdot::update()
{
    to_draw.setPosition(pos.x, pos.y);
}


sf::CircleShape Pacdot::draw()
{
    return to_draw;
}
