#ifndef PACMAN_H
#define PACMAN_H
#include "globals.h"
#include "sprite.h"
#include "map.h"

class Pacman : public Sprite {
public:

    bool has_moved = 0;
    int cookies_eaten = 0;

    Pacman(int, int);

    void update();

    void update(Map *, int, int);

    void move(Map *);

    sf::CircleShape draw();

    void reset();
};

#endif
