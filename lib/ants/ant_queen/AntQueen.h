#ifndef CPP_ANTSCOLONY_ANTQUEEN_H
#define CPP_ANTSCOLONY_ANTQUEEN_H

#include <iostream>
#include "ants/living_ant/LivingAnt.h"

using namespace std;

class AntQueen: public LivingAnt {
public:
    AntQueen(AntHill &antHill, Environment &environment): LivingAnt(antHill, environment){};
    void layEgg();
    void speak() override;
    void evolve() override;
    void move(char pos) override;

};


#endif //CPP_ANTSCOLONY_ANTQUEEN_H
