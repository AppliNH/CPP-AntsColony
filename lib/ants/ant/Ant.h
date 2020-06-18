#ifndef CPP_ANTSCOLONY_ANT_H_
#define CPP_ANTSCOLONY_ANT_H_

#include <string>
#include <vector>
#include <ant_hill/AntHill.h>
#include <environment/Environment.h>
#include "../AntState.h"

using namespace std;

class Ant : public SquareBox{

protected:
    int age;
    AntState antState;
    AntHill &antHill;
public:
    Ant(AntHill &antHill)
            : age(0), antHill(antHill), SquareBox(antHill.getPosX(), antHill.getPosY()) {};

    virtual ~Ant() = default;

    //explicit Ant(const AntState &state, AntHill antHill, Environment environment) : posX(0), posY(0), antState(state), antHill(antHill), environment(environment) {};
    void setState(const AntState &);

    AntHill &getAntHill() {return antHill;}

    bool isAtHome() {return posX == antHill.getPosX() && posY == antHill.getPosY();}

    virtual void speak();

    virtual void evolve() = 0;
};

#endif  // CPP_ANTSCOLONY_ANT_H_
