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
    double ageToEvolve;
    AntHill &antHill;
    Environment &environment;
public:
    Ant(AntHill &antHill, Environment &environment, const int &ageToEvolve, const bool &willBeQueen = false,
        int age = 0)
            : age(age), ageToEvolve(ageToEvolve), antHill(antHill), SquareBox(antHill.getPosX(), antHill.getPosY()),
              willBeQueen(willBeQueen), environment(environment) {};

    AntHill &getAntHill() { return antHill; }

    virtual bool grow() {
        age++;
        return age == ageToEvolve;
    }

    bool isAtHome() { return posX == antHill.getPosX() && posY == antHill.getPosY(); }

    virtual void speak() = 0;

    virtual LivingAnt *evolve() = 0;
};

#endif  // CPP_ANTSCOLONY_ANT_H
