#ifndef FOOD_H
#define FOOD_H

#include <SFML/Graphics.hpp>
#include "gameobject.h"
// This class is the parent class for all of the things Pac Man can eat except for the blue Ghosts.
// This includes the fruit, the orbs, and the orbs that turn the ghosts blue.

class Food : public GameObject {
public:
    int score_given_when_eaten = 0;
    int get_score_when_eaten();
};

#endif
