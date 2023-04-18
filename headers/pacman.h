#ifndef PACMAN_H
#define PACMAN_H
#include "globals.h"
#include "sprite.h"

class Pacman : public Sprite {
public:

    Pacman(int, int);

    void update();

    void move();

    sf::CircleShape draw();
};

#endif
