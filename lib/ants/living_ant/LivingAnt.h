#ifndef CPP_ANTSCOLONY_LIVINGANT_H
#define CPP_ANTSCOLONY_LIVINGANT_H


#include "ants/ant/Ant.h"
#include "food/Food.h"
#include <vector>

using namespace std;

class LivingAnt : public Ant {

private:
    int lifePoints;
    int lifeThreshold;
    int maxCarriedFood;
    vector<Food> carriedFood;
public:
    LivingAnt(): Ant(AntHill(0, 0, 0, 0)) {};
    bool collectFood(const Food &);
    bool layDownFood(const Food &);
    void eatFood(const Food &);
    void move(char &);
    char detectPheromone();
    void dieSlowly();
    bool isRequiredToEat();
    void speak() override;

};


#endif //CPP_ANTSCOLONY_LIVINGANT_H
