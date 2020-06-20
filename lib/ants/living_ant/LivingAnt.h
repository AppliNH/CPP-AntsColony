#ifndef CPP_ANTSCOLONY_LIVINGANT_H
#define CPP_ANTSCOLONY_LIVINGANT_H

#include <vector>
#include <iostream>

#include "ants/ant/Ant.h"
#include <environment/Environment.h>
#include "food/Food.h"

using namespace std;

class LivingAnt : public Ant {

protected:
    double lifePoints;
    double decayRate;
    double lifeThreshold;
    int foodConsumed;
    int maxCarriedFood;
    vector<Food *> carriedFood;
    Environment &environment;

    void moveLeft() { if (posX > 0) posX--; }

    void moveRight() { if (posX < environment.getWidth() - 1) posX++; }

    void moveBottom() { if (posY < environment.getHeight() - 1) posY++; }

    void moveTop() { if (posY > 0) posY--; }

public:
    LivingAnt(AntHill &antHill, Environment &environment, const double &lifePoints, const double &decayRate,
              const int &foodConsumed, int age = 0)
            : Ant(antHill, false, age), maxCarriedFood(5),
              environment(environment),
              lifePoints(lifePoints),
              lifeThreshold(lifePoints / 4),
              decayRate(decayRate),
              foodConsumed(foodConsumed) {};

    ~LivingAnt() override;

    void speak() override;

    void setNewAntHill(AntHill antHill1) { antHill = antHill1; }

    bool looseLife();

    void layDownFoodInAntHill();

    virtual bool isRequiredToEat();

    bool isSameAntHill(const AntHill &antHill1) { return antHill == antHill1; }

    bool isFullOfFood();

    void undergoDamage() { lifePoints--; }

    bool grabFood(const Food &food);

    virtual void move(char direction);

    void displayLifePoints() const;

    void displayState();

    void displayPosition();

    virtual void eatFood();

    void storeFood(const Food &food);

};


#endif //CPP_ANTSCOLONY_LIVINGANT_H
