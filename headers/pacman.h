#ifndef PACMAN_H
#define PACMAN_H
#include "globals.h"
#include "sprite.h"
#include "map.h"

class Pacman : public Sprite {
public:

    Pacman(int, int);

    void update();

    void update(Map *, int x, int y);

    void move(Map *);

    sf::CircleShape draw();
};

#endif
