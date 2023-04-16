#include "headers/gameobject.h"
#include "headers/sprite.h"
#include "headers/pacman.h"

Pacman::Pacman(int x, int y)
{
    to_draw.setRadius(10.f);
    to_draw.setFillColor(sf::Color::Yellow);
    name = "Pacman";
    position tmp_pos;

    tmp_pos.x = x;
    tmp_pos.y = y;
    pos       = tmp_pos;
    update();
}


void Pacman::update()
{
    to_draw.setPosition(pos.x, pos.y);
}


sf::CircleShape Pacman::draw()
{
    return to_draw;
}
