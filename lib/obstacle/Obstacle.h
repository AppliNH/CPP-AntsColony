#ifndef CPP_ANTSCOLONY_OBSTACLE_H
#define CPP_ANTSCOLONY_OBSTACLE_H


#include "square_box/SquareBox.h"

class Obstacle : public SquareBox {
public:
    Obstacle(int X, int Y) : SquareBox(X, Y) {}
};


#endif //CPP_ANTSCOLONY_OBSTACLE_H
