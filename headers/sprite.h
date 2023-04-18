#ifndef SPRITE_H
#define SPRITE_H

#include "gameobject.h"

// This class is the parent class for all of the characters.
// This includes Pac-Man and the Ghosts
class Sprite : public GameObject {
    virtual void move();
};

#endif
 