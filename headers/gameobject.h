#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class GameObject{
    position pos;
public:
    virtual position get_position() = 0;

    virtual void set_position(position) = 0;
};

#endif
