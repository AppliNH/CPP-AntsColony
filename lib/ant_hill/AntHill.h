#ifndef CPP_ANTSCOLONY_ANTHILL_H
#define CPP_ANTSCOLONY_ANTHILL_H


#include <square_box/SquareBox.h>
#include <food/Food.h>
#include <vector>

using namespace std;

class AntHill: public SquareBox {

private:
    int maxPopulation;
    int maxFood;
    vector<Food *> foodStock;

public:
    AntHill(int X, int Y, int maxPop, int maxFd) : SquareBox(X, Y), maxPopulation(maxPop), maxFood(maxFd) {
    }
    ~AntHill();
    bool operator==(const AntHill &);

};


#endif //CPP_ANTSCOLONY_ANTHILL_H
