#ifndef CPP_ANTSCOLONY_ANTEGG_H
#define CPP_ANTSCOLONY_ANTEGG_H

#include <iostream>
#include "ants/ant/Ant.h"

class AntEgg: public Ant{
public:
    void speak() override;
};


#endif //CPP_ANTSCOLONY_ANTEGG_H
