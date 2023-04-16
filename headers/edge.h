#ifndef EDGE_H
#define EDGE_H

class Edge : public GameObject {
public:
    Edge(int, int);

    void update();

    sf::CircleShape draw();
};

#endif
