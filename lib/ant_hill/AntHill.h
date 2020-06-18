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
    AntHill(int X, int Y) : SquareBox(X, Y), maxPopulation(50), maxFood(25) {}

    ~AntHill();

    void stockFood(const Food &food);

    bool operator==(const AntHill &);

    int getFoodCount() { return foodStock.size(); }

    void eatFromStock() { foodStock.erase(foodStock.begin()); }

    void status();

};


#endif //CPP_ANTSCOLONY_ANTHILL_H
