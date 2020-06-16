#ifndef CPP_ANTSCOLONY_ANTWARRIOR_H
#define CPP_ANTSCOLONY_ANTWARRIOR_H

#include <iostream>
#include "ants/living_ant/LivingAnt.h"

class AntWarrior : public LivingAnt {
public:
    AntWarrior(AntHill &antHill, Environment &environment) : LivingAnt(antHill, environment, 10) {}
    void attack(const LivingAnt &);
    void speak() override;
    void evolve() override;
    bool dieSlowly(const int &round) override;
};


#endif //CPP_ANTSCOLONY_ANTWARRIOR_H
