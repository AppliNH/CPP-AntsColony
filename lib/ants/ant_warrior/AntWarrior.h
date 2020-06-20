#ifndef CPP_ANTSCOLONY_ANTWARRIOR_H
#define CPP_ANTSCOLONY_ANTWARRIOR_H

#include "ants/living_ant/LivingAnt.h"
#include "ants/ant_young_queen/AntYoungQueen.h"

#include <iostream>

class AntWarrior : public LivingAnt {
public:
    AntWarrior(AntHill &antHill, Environment &environment, bool willBeQueen) : LivingAnt(antHill, environment, 10, 0.05, 2, 35, willBeQueen, 15) {}
    void attack(LivingAnt &);
    void speak() override;
    LivingAnt * evolve() override;
    bool grow() override {
        age++;
        return age == ageToEvolve && willBeQueen;
    }
};


#endif //CPP_ANTSCOLONY_ANTWARRIOR_H
