#ifndef CPP_ANTSCOLONY_ANTEGG_H
#define CPP_ANTSCOLONY_ANTEGG_H

#include <iostream>
#include "ants/ant/Ant.h"

class AntEgg: public Ant{
public:
    AntEgg(AntHill antHill, Environment environment) : Ant(antHill,environment) {}

    void speak() override;
    void evolve() override;
};


#endif //CPP_ANTSCOLONY_ANTEGG_H
