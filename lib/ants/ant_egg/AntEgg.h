#ifndef CPP_ANTSCOLONY_ANTEGG_H
#define CPP_ANTSCOLONY_ANTEGG_H

#include <iostream>
#include "ants/ant/Ant.h"
#include <random>


class AntEgg : public Ant {
public:
    AntEgg(AntHill &antHill, bool willBeQueen) :  Ant(antHill,willBeQueen) {}

    bool grow() {
        age++;
        return age == ageToEvolve;
    }

    void speak() override;

    void evolve() override;
};


#endif //CPP_ANTSCOLONY_ANTEGG_H
