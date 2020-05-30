#ifndef CPP_ANTSCOLONY_ANTWORKER_H
#define CPP_ANTSCOLONY_ANTWORKER_H

#include <iostream>
#include "ants/living_ant/LivingAnt.h"

class AntWorker: public LivingAnt {
public:
    void speak() override;
};


#endif //CPP_ANTSCOLONY_ANTWORKER_H
