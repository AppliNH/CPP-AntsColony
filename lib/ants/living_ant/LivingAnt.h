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
    vector<Food *> carriedFood;
    Environment &environment;
public:
    LivingAnt(AntHill &antHill, Environment &environment, int lifPoints) : Ant(antHill), maxCarriedFood(2),
                                                                           environment(environment),
                                                                           lifePoints(lifPoints) {};

    ~LivingAnt();

    void eatFood(const Food &);

    char detectPheromone();

    virtual bool dieSlowly(const int &round) = 0;

    bool isRequiredToEat();

    void moveLeft() { if (posX > 0) posX--; }

    void moveRight() { if (posX < environment.getWidth() - 1) posX++; }

    void moveBottom() { if (posY < environment.getHeight() - 1) posY++; }

    void moveTop() { if (posY > 0) posY--; }

    bool looseLife() {
        lifePoints--;
        return lifePoints == 0;
    }

    void layDownFoodInAntHill();

    bool isFullOfFood();

    bool collectFood(const Food &food);

    virtual void move(char direction);

    void speak()
    override;

    void displayLifePoints();

    void displayState();

    void displayPosition();

};


#endif //CPP_ANTSCOLONY_LIVINGANT_H
