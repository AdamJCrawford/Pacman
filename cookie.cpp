#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "headers/cookie.h"



Cookie::Cookie()
{
    std::cout << name << "\n";
    score_given_when_eaten = 10;

    to_draw_tmp.setRadius(10.f);
    to_draw_tmp.setFillColor(sf::Color::White);
    name = "Cookie";
    std::cout << name << "\n";
}


Cookie::Cookie(int x, int y)
{
    Cookie();
    pos.x = x;
    pos.y = y;
    update();
}


void Cookie::update()
{
    to_draw_tmp.setPosition(pos.x, pos.y);
}


sf::CircleShape Cookie::draw()
{
    return to_draw_tmp;
}
