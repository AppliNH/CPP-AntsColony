#ifndef CPP_ANTSCOLONY_LIVINGANT_H
#define CPP_ANTSCOLONY_LIVINGANT_H

#include "ants/ant/Ant.h"
#include "environment/Environment.h"
#include "food/Food.h"

#include <vector>
#include <iostream>

using namespace std;

class LivingAnt : public Ant {

protected:
    double lifePoints;
    double decayRate;
    double lifeThreshold;
    int foodConsumed;
    int maxCarriedFood;
    vector<Food *> carriedFood;

    void moveLeft() { if (posX > 0) posX--; }

    void moveRight() { if (posX < environment.getWidth() - 1) posX++; }

    void moveBottom() { if (posY < environment.getHeight() - 1) posY++; }

    void moveTop() { if (posY > 0) posY--; }

public:
    LivingAnt(AntHill &antHill, Environment &environment, const double &lifePoints, const double &decayRate,
              const int &foodConsumed, const int &ageToEvolve, bool willBeQueen = false, int age = 0)
            : Ant(antHill, environment, ageToEvolve, willBeQueen, age), maxCarriedFood(5),
              lifePoints(lifePoints),
              lifeThreshold(lifePoints / 4),
              decayRate(decayRate),
              foodConsumed(foodConsumed) {};

    ~LivingAnt() override = 0;

    void setAntHill(const AntHill &antHill);

    bool looseLife();

    void layDownFoodInAntHill();

    virtual bool isRequiredToEat();

    bool isFullOfFood();

    void undergoDamage();

    bool grabFood(const Food &food);

    void move(char direction);

    virtual void eatFood();

    void storeFood(const Food &food);

    LivingAnt *evolve() override;

    void speak() override;

    virtual void displayState();

    void displayPosition();

    void displayLifePoints();

};


#endif //CPP_ANTSCOLONY_LIVINGANT_H
