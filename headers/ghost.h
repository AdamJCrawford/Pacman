#ifndef GHOSTS_H
#define GHOSTS_H

#include "sprite.h"

class Ghost : public Sprite {
    int ghost_num;
    bool has_moved = 0;
public:
    Ghost(int, int, int);

    void update();

    void move();

    sf::CircleShape draw();

    void reset();
};

#endif
