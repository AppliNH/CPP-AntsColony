#ifndef CPP_ANTSCOLONY_PHEROMONE_H
#define CPP_ANTSCOLONY_PHEROMONE_H


#include <iostream>
#include "square_box/SquareBox.h"

class Pheromone : public SquareBox {
private:
    double powerness;
    double decayRate;
public:
    Pheromone(int X, int Y, double powerness, double decayRate = 0.95) : SquareBox(X, Y), powerness(powerness), decayRate(decayRate) {}

    void increasePowerness() { powerness++; }

    bool decreasePowerness() {
        powerness -= decayRate;
        return powerness <= 0;
    }
};


#endif //CPP_ANTSCOLONY_PHEROMONE_H
