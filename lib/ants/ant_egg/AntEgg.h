#ifndef CPP_ANTSCOLONY_ANTEGG_H
#define CPP_ANTSCOLONY_ANTEGG_H

#include "ants/ant/Ant.h"
#include "ants/living_ant/LivingAnt.h"
#include "ants/ant_worker/AntWorker.h"
#include "environment/Environment.h"

#include <iostream>
#include <random>


class AntEgg : public Ant {
public:
    AntEgg(AntHill &antHill, Environment &environment, bool willBeQueen) : Ant(antHill, environment, 10, willBeQueen) {}

    void speak() override;

    LivingAnt *evolve() override;
};


#endif //CPP_ANTSCOLONY_ANTEGG_H
