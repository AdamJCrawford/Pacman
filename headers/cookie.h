#ifndef COOKIE_H
#define COOKIE_H

#include <SFML/Graphics.hpp>
#include "food.h"

class Cookie : public Food
{
public:
    Cookie(int, int);

    void update();

    sf::CircleShape draw();
};

#endif
