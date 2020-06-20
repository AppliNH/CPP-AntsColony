#ifndef CPP_ANTSCOLONY_ANT_H
#define CPP_ANTSCOLONY_ANT_H

#include "ant_hill/AntHill.h"
#include "environment/Environment.h"

#include <string>
#include <vector>

using namespace std;

class LivingAnt;

class Ant : public SquareBox {

protected:
    int age;
    bool willBeQueen;
    int ageToEvolve;
    AntHill &antHill;
    Environment &environment;
public:
    Ant(AntHill &antHill, Environment &environment, int ageToEvolve, bool willBeQueen = false, int age = 0)
            : age(age), ageToEvolve(ageToEvolve), antHill(antHill), SquareBox(antHill.getPosX(), antHill.getPosY()),
              willBeQueen(willBeQueen), environment(environment) {};

    virtual ~Ant() = default;

    AntHill &getAntHill() { return antHill; }

    virtual bool grow() {
        age++;
        return age == ageToEvolve;
    }

    bool isAtHome() { return posX == antHill.getPosX() && posY == antHill.getPosY(); }

    virtual void speak();

    virtual LivingAnt *evolve() = 0;
};

#endif  // CPP_ANTSCOLONY_ANT_H
