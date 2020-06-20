#ifndef CPP_ANTSCOLONY_ANTEGG_H
#define CPP_ANTSCOLONY_ANTEGG_H

#include "ants/ant/Ant.h"
#include "ants/ant_worker/AntWorker.h"
#include "environment/Environment.h"

#include <iostream>
#include <random>


class AntEgg : public Ant {
public:
    AntEgg(AntHill &antHill, Environment &environment, bool willBeQueen) :  Ant(antHill, environment,willBeQueen) {}

    void speak() override;

    Ant * evolve() override;
};


#endif //CPP_ANTSCOLONY_ANTEGG_H
