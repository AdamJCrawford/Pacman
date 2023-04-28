#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>
#include <SFML/Graphics.hpp>

struct position
{
    int x = 0; // Row
    int y = 0; // Col

    inline bool operator==(position a) {
       if (a.x == x && a.y == y)
          return true;
       else
          return false;
    }
};

class GameObject {
public:
    position pos;
    std::string name;
    sf::CircleShape to_draw;

    virtual void set_position(position);

    virtual void set_position(int, int);

    virtual void set_name(std::string);

    virtual position get_position();

    virtual std::string get_name();

    virtual sf::CircleShape draw();
};

#endif
