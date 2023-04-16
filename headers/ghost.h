#ifndef GHOSTS_H
#define GHOSTS_H

class Ghost : public Sprite {
    int ghost_num;
public:
    Ghost(int, int, int);

    void update();

    sf::CircleShape draw();
};

#endif
