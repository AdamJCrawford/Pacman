#ifndef GHOSTS_H
#define GHOSTS_H

#include "sprite.h"
#include "map.h"

class Ghost : public Sprite {
    int ghost_num;
    bool has_moved = 0;
    bool is_blue = 0;
    int score_given_when_eaten = 100;
public:
    Ghost(int, int, int);

    void update();

    void update(Map *, int, int);

    void move(Map *);

    sf::CircleShape draw();

    void reset();

    void blue_mode();

    void set_color();

    int get_score_when_eaten();

    bool blue_status();
};

#endif
