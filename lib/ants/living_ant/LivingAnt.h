#ifndef CPP_ANTSCOLONY_LIVINGANT_H
#define CPP_ANTSCOLONY_LIVINGANT_H

#include <vector>
#include <iostream>

#include "ants/ant/Ant.h"
#include <environment/Environment.h>
#include "food/Food.h"

using namespace std;

class LivingAnt : public Ant {

private:
    int lifePoints;
    int lifeThreshold;
    int maxCarriedFood;
    vector<Food> carriedFood;
public:
    LivingAnt(AntHill antHill ,Environment environment) : Ant(antHill, environment) {};
    bool collectFood(const Food &);
    bool layDownFood(const Food &);
    void eatFood(const Food &);
    virtual void move(char);
    char detectPheromone();
    void dieSlowly();
    bool isRequiredToEat();
    void speak() override;

};


#endif //CPP_ANTSCOLONY_LIVINGANT_H
