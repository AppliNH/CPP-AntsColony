#ifndef CPP_ANTSCOLONY_ANTWORKER_H
#define CPP_ANTSCOLONY_ANTWORKER_H

#include <iostream>
#include "ants/living_ant/LivingAnt.h"

class AntWorker: public LivingAnt {
public:

    AntWorker(AntHill &antHill, Environment &environment) : LivingAnt(antHill, environment, 5) {}
    void speak() override;
    void evolve() override;
    void move(char pos) override;
    bool dieSlowly(const int &round) override ;
};


#endif //CPP_ANTSCOLONY_ANTWORKER_H
