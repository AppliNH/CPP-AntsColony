#ifndef CPP_ANTSCOLONY_ANTQUEEN_H
#define CPP_ANTSCOLONY_ANTQUEEN_H

#include <iostream>
#include "ants/living_ant/LivingAnt.h"

using namespace std;

class AntQueen: public LivingAnt {
public:
    AntQueen(AntHill &antHill, Environment &environment): LivingAnt(antHill, environment, 3){};
    void layEgg();
    void speak() override;
    void evolve() override;
    bool dieSlowly(const int &round) override;

};


#endif //CPP_ANTSCOLONY_ANTQUEEN_H
