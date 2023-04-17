#ifndef PACDOT_H
#define PACDOT_H

class Pacdot: public Food
{
public:

    Pacdot();
    Pacdot(int, int);

    void update();

    sf::CircleShape draw();
};


#endif
