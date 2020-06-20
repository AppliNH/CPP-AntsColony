#ifndef CPP_ANTSCOLONY_ANTQUEEN_H
#define CPP_ANTSCOLONY_ANTQUEEN_H

#include <iostream>
#include "ants/living_ant/LivingAnt.h"
#include "ants/ant/Ant.h"

using namespace std;

class AntQueen: public LivingAnt {
public:
    AntQueen(AntHill &antHill, Environment &environment): LivingAnt(antHill, environment, 3, 0.05, 4) {};
    void move(char direction) override;
    void speak() override;
    Ant * evolve() override;
    bool isRequiredToEat() override;
    void eatFood() override;

};


#endif //CPP_ANTSCOLONY_ANTQUEEN_H
