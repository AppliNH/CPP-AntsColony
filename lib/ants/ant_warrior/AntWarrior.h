#ifndef CPP_ANTSCOLONY_ANTWARRIOR_H
#define CPP_ANTSCOLONY_ANTWARRIOR_H

#include "ants/living_ant/LivingAnt.h"

#include <iostream>

class AntWarrior : public LivingAnt {
public:
    AntWarrior(AntHill &antHill, Environment &environment) : LivingAnt(antHill, environment, 10, 0.05, 2, 15) {}
    void attack(LivingAnt &);
    void speak() override;
    void evolve() override;
};


#endif //CPP_ANTSCOLONY_ANTWARRIOR_H
