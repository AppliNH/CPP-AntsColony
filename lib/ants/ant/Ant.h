#ifndef CPP_ANTSCOLONY_ANT_H_
#define CPP_ANTSCOLONY_ANT_H_

#include <string>
#include <vector>
#include <ant_hill/AntHill.h>
#include "../AntState.h"

using namespace std;

class Ant {
private:
    int age;
    int posX;
    int posY;
    AntState antState;
    AntHill antHill;

public:
    Ant(AntHill antHill) : posX(0), posY(0), age(0), antHill(antHill) {};
    explicit Ant(const AntState &state, AntHill antHill) : posX(0), posY(0), antState(state), antHill(antHill) {};
    void setState(const AntState &);
    virtual void speak();
    virtual void evolve() = 0;
};

#endif  // CPP_ANTSCOLONY_ANT_H_
