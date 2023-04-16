#ifndef GHOSTS_H
#define GHOSTS_H

class Ghost : public Sprite {
    int ghost_num;
public:
    Ghost(position, int);
    Ghost(int, int, int);
};

#endif
