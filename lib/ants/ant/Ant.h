#ifndef CPP_ANTSCOLONY_ANT_H_
#define CPP_ANTSCOLONY_ANT_H_

#include <string>
#include <vector>
#include "food/Food.h"
#include "../AntState.h"

using namespace std;

class Ant {
private:
    int age;
    int posX;
    int posY;
    AntState antState;

public:
    Ant() : posX(0), posY(0), age(0) {};
    explicit Ant(const AntState& state): posX(0), posY(0), antState(state){};
    void setState(const AntState &);
    virtual void speak();
    virtual void evolve() = 0;
};

#endif  // CPP_ANTSCOLONY_ANT_H_
