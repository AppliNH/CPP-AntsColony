#ifndef CPP_ANTSCOLONY_ANTWARRIOR_H
#define CPP_ANTSCOLONY_ANTWARRIOR_H


#include "ants/living_ant/LivingAnt.h"

class AntWarrior : public LivingAnt {
public:
    void attack(const LivingAnt &);
};


#endif //CPP_ANTSCOLONY_ANTWARRIOR_H
