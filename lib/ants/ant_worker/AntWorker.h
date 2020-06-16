#ifndef CPP_ANTSCOLONY_ANTWORKER_H
#define CPP_ANTSCOLONY_ANTWORKER_H

#include <iostream>
#include "ants/living_ant/LivingAnt.h"

class AntWorker: public LivingAnt {
public:
    AntWorker(AntHill &antHill, Environment &environment) : LivingAnt(antHill, environment, 5, 0.1, 1) {}
    void speak() override;
    void evolve() override;
};


#endif //CPP_ANTSCOLONY_ANTWORKER_H
