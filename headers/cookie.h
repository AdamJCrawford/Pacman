#ifndef COOKIE_H
#define COOKIE_H

#include <SFML/Graphics.hpp>
#include "food.h"

class Cookie : public Food
{
public:
    sf::CircleShape to_draw_tmp;
    Cookie();
    Cookie(int, int);

    void update();

    sf::CircleShape draw();
};

#endif
