#ifndef COOKIE_H
#define COOKIE_H

class Cookie : public Food {
public:

    Cookie();
    Cookie(int, int);
    Cookie(sf::CircleShape tmp_to_draw);

    void update();

    sf::CircleShape draw();
};

#endif
