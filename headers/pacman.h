#ifndef PACMAN_H
#define PACMAN_H

class Pacman : public Sprite {
public:

    Pacman(int, int);

    void update();

    sf::CircleShape draw();
};

#endif
