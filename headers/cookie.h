#ifndef COOKIE_H
#define COOKIE_H

class Cookie: public Food {
public:

    Cookie();
    Cookie(sf::CircleShape tmp_to_draw);

    void update();

    sf::CircleShape draw();
};

#endif
