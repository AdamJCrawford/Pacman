#ifndef GHOSTS_H
#define GHOSTS_H

#include "sprite.h"
#include "map.h"
#include <vector>

class Ghost : public Sprite {
    int ghost_num;
    bool has_moved = 0;
    bool is_blue = 0;
    int score_given_when_eaten = 100;
    std::vector<position> recent_positions;

    bool can_move_left;
    bool can_move_up;
    bool can_move_right;
    bool can_move_down;
    int x_offset;
    int y_offset;
    int scatter_x;
    int scatter_y;
    sf::Clock clock;
    sf::Time starting_time;

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

    bool not_in_recent(position);
};

#endif
