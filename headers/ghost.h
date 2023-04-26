#ifndef GHOSTS_H
#define GHOSTS_H

#include "sprite.h"
#include "map.h"

class Ghost : public Sprite {
    int ghost_num;
    bool has_moved = 0;
public:
    Ghost(int, int, int);

    void update();

    void update(Map *, int, int);

    void move(Map *);

    sf::CircleShape draw();

    void reset();
};

#endif
