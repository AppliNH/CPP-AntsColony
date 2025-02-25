#ifndef CPP_ANTSCOLONY_PHEROMONE_H
#define CPP_ANTSCOLONY_PHEROMONE_H

#include "square_box/SquareBox.h"

class Pheromone : public SquareBox {
private:
    double powerness;
    double decayRate = 0.95;
public:
    Pheromone(int X, int Y, double powerness) : SquareBox(X, Y), powerness(powerness) {}

    void increasePowerness();

    bool decreasePowerness();
};


#endif //CPP_ANTSCOLONY_PHEROMONE_H
