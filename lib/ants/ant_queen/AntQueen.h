#ifndef CPP_ANTSCOLONY_ANTQUEEN_H
#define CPP_ANTSCOLONY_ANTQUEEN_H

#include "ants/living_ant/LivingAnt.h"

#include <iostream>

using namespace std;

class AntQueen: public LivingAnt {
public:
    AntQueen(AntHill &antHill, Environment &environment): LivingAnt(antHill, environment, 3, 0.05, 4, 0) {};
    void move(char direction) override;
    void speak() override;
    LivingAnt * evolve() override;
    bool isRequiredToEat() override;
    void eatFood() override;
    bool grow() override {
        return false;
    }

};


#endif //CPP_ANTSCOLONY_ANTQUEEN_H
