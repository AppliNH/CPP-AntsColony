#ifndef CPP_ANTSCOLONY_PHEROMONE_H
#define CPP_ANTSCOLONY_PHEROMONE_H


#include <square_box/SquareBox.h>

class Pheromone : public SquareBox {
private:
    int duration;
    int powerness;

public:
    Pheromone(int X, int Y, int duration) : SquareBox(X, Y), duration(duration), powerness(15) {}

    void increasePowerness() { powerness++; }

    bool decreasePowerness() {
        powerness--;
        return powerness == 0;
    }
};


#endif //CPP_ANTSCOLONY_PHEROMONE_H
