#ifndef GHOSTS_H
#define GHOSTS_H

#include "sprite.h"

class Ghost : public Sprite {
    int ghost_num;
public:
    Ghost(int, int, int);

    void update();

    void move();

    sf::CircleShape draw();
};

#endif
