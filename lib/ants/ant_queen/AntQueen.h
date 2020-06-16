#ifndef CPP_ANTSCOLONY_ANTQUEEN_H
#define CPP_ANTSCOLONY_ANTQUEEN_H

#include <iostream>
#include "ants/living_ant/LivingAnt.h"

using namespace std;

class AntQueen: public LivingAnt {
public:
    AntQueen(AntHill &antHill, Environment &environment): LivingAnt(antHill, environment, 3, 0.01, 4) {};
    void layEgg();
    void move(char direction) override;
    void speak() override;
    void evolve() override;

};


#endif //CPP_ANTSCOLONY_ANTQUEEN_H
