#ifndef CPP_ANTSCOLONY_ANTQUEEN_H
#define CPP_ANTSCOLONY_ANTQUEEN_H

#include "ants/living_ant/LivingAnt.h"

#include <iostream>

using namespace std;

class AntQueen : public LivingAnt {
public:
    AntQueen(AntHill &antHill, Environment &environment) : LivingAnt(antHill, environment, 3, 0.05, 4, 0) {};

    void speak() override;

    bool isRequiredToEat() override;

    void eatFood() override;

    void displayState() override;

    bool grow() override;

};


#endif //CPP_ANTSCOLONY_ANTQUEEN_H
