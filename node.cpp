#include "node.h"

Node::Node(position tmp_pos)
{
    pos = tmp_pos;
}


Node::Node(int x, int y)
{
    position tmp_pos = { x, y };
}
