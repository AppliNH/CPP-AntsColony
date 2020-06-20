#ifndef CPP_ANTSCOLONY_ANT_H
#define CPP_ANTSCOLONY_ANT_H

#include <string>
#include <vector>
#include <ant_hill/AntHill.h>
#include <environment/Environment.h>
#include "../AntState.h"

using namespace std;

class Ant : public SquareBox {

protected:
    int age;
    bool willBeQueen;
    int ageToEvolve;
    AntState antState;
    AntHill &antHill;
    Environment &environment;
public:
    Ant(AntHill &antHill, Environment &environment, bool willBeQueen=false, int age=0 )
            : age(age), ageToEvolve(10), antHill(antHill), SquareBox(antHill.getPosX(), antHill.getPosY()), willBeQueen(willBeQueen), environment(environment) {};

    virtual ~Ant() = default;

    //explicit Ant(const AntState &state, AntHill antHill, Environment environment) : posX(0), posY(0), antState(state), antHill(antHill), environment(environment) {};
    void setState(const AntState &);

    AntHill &getAntHill() { return antHill; }

    bool grow() {
        age++;
        return age == ageToEvolve;
    }

    bool isAtHome() { return posX == antHill.getPosX() && posY == antHill.getPosY(); }

    virtual void speak();

    virtual Ant * evolve() = 0;
};

#endif  // CPP_ANTSCOLONY_ANT_H
