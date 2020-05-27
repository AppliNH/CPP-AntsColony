#ifndef CPP_ANTSCOLONY_ANT_H_
#define CPP_ANTSCOLONY_ANT_H_

#include <string>
#include <vector>
#include "food/Food.h"
#include "../AntState.h"

using namespace std;

class Ant {
private:
    int posX;
    int posY;
    AntState antState;

public:
    void setState(const AntState &);
};

#endif  // CPP_ANTSCOLONY_ANT_H_
