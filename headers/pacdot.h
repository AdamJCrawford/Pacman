#ifndef PACDOT_H
#define PACDOT_H

class Pacdot: public Food
{
public:
    Pacdot();
    Pacdot(int, int);
    Pacdot(sf::CircleShape tmp_to_draw);

    void update();

    sf::CircleShape draw();
};


#endif
