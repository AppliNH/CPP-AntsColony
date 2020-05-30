#ifndef CPP_ANTSCOLONY_ANTQUEEN_H
#define CPP_ANTSCOLONY_ANTQUEEN_H

#include <iostream>
#include "ants/living_ant/LivingAnt.h"

using namespace std;

class AntQueen: public LivingAnt {
public:
    AntQueen(): LivingAnt(){};
    void layEgg();
    void speak() override;

};


#endif //CPP_ANTSCOLONY_ANTQUEEN_H
