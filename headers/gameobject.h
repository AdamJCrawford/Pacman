#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>
#include "node.h"

class GameObject {
    position pos;
    std::string name;
public:
    virtual position get_position() = 0;

    virtual void set_position(position) = 0;

    virtual std::string get_name() = 0;

    virtual void set_name(std::string) = 0;
};

#endif
