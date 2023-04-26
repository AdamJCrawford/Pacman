#include "headers/food.h"
#include "headers/pacdot.h"
#include <iostream>


Pacdot::Pacdot(int x, int y)
{
    score_given_when_eaten = 50;

    to_draw.setRadius(10.f);
    to_draw.setFillColor(sf::Color::White);
    name  = "Pacdot";
    pos.x = x;
    pos.y = y;
    update();
}


void Pacdot::update()
{
    to_draw.setPosition(20 * pos.x, 20 * pos.y);
}


sf::CircleShape Pacdot::draw()
{
    return to_draw;
}
