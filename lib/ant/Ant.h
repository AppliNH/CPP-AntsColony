#ifndef CPP_AntsColony_LIB_ANT_H_
#define CPP_AntsColony_LIB_ANT_H_

#include <string>
#include <vector>
#include "../food/Food.h"

using namespace std;

class Ant {
private:
    int lifePoints;
    int lifeThreshold;
    int posX;
    int posY;
    int maxCarriedFood;
    vector<Food> carriedFood;

public:
    Ant(int lifePoints, int lifeThreshold, int maxCarriedFood);
    void displayAnt();
    bool collectFood(Food);
    void eat(Food);
    void move(string dimension);
    void dieSlowly();
    bool isRequiredToEat();
};

#endif  // CPP_AntsColony_LIB_ANT_H_
