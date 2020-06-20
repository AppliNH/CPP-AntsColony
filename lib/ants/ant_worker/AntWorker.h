#ifndef CPP_ANTSCOLONY_ANTWORKER_H
#define CPP_ANTSCOLONY_ANTWORKER_H

#include "ants/living_ant/LivingAnt.h"
#include "ants/ant_warrior/AntWarrior.h"

#include <iostream>

class AntWorker: public LivingAnt {
public:
    AntWorker(AntHill &antHill, Environment &environment, bool willBeQueen) : LivingAnt(antHill, environment, 5, 0.1, 1, 25, willBeQueen) {}
    void speak() override;
    LivingAnt * evolve() override;
};


#endif //CPP_ANTSCOLONY_ANTWORKER_H
