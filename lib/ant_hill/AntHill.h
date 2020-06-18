#ifndef CPP_ANTSCOLONY_ANTHILL_H
#define CPP_ANTSCOLONY_ANTHILL_H


#include "square_box/SquareBox.h"
#include "food/Food.h"

#include <vector>
#include <iostream>

using namespace std;

class AntHill : public SquareBox {

private:
    int maxPopulation;
    int maxFood;
    vector<Food *> foodStock;

public:
    AntHill(int X, int Y) : SquareBox(X, Y), maxPopulation(80), maxFood(25) {}

    ~AntHill();

    void stockFood(const Food &food);

    int getFoodCount() { return foodStock.size(); }

    int getMaxPopulation() { return maxPopulation; }

    void eatFromStock() { foodStock.erase(foodStock.begin()); }

    void status();

};


#endif //CPP_ANTSCOLONY_ANTHILL_H
