#include "headers/gameobject.h"
#include "headers/edge.h"

Edge::Edge(position tmp_pos)
{
    pos = tmp_pos;
}


Edge::Edge(int x, int y)
{
    position tmp_pos;

    tmp_pos.x = x;
    tmp_pos.y = y;
    pos       = tmp_pos;
}
