#include "headers/gameobject.h"
#include "headers/sprite.h"
#include "headers/ghost.h"

Ghost::Ghost(position tmp_pos, int tmp_ghost_num)
{
    pos       = tmp_pos;
    ghost_num = tmp_ghost_num;
}


Ghost::Ghost(int x, int y, int tmp_ghost_num)
{
    position tmp_pos;

    tmp_pos.x = x;
    tmp_pos.y = y;
    pos       = tmp_pos;

    ghost_num = tmp_ghost_num;
}
