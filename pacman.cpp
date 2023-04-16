#include "headers/gameobject.h"
#include "headers/sprite.h"
#include "headers/pacman.h"

Pacman::Pacman(position tmp_pos)
{
    pos = tmp_pos;
}


Pacman::Pacman(int x, int y)
{
    position tmp_pos;

    tmp_pos.x = x;
    tmp_pos.y = y;
    pos       = tmp_pos;
}
