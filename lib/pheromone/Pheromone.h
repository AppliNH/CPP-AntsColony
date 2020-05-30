#ifndef CPP_ANTSCOLONY_PHEROMONE_H
#define CPP_ANTSCOLONY_PHEROMONE_H


#include <square_box/SquareBox.h>

class Pheromone : public SquareBox {
private:

    int duration;
    int powerness;

public:
    Pheromone(int X, int Y, int duration) : SquareBox(X, Y), duration(5), powerness(1) {}
};


#endif //CPP_ANTSCOLONY_PHEROMONE_H
