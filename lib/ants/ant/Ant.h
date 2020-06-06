#ifndef CPP_ANTSCOLONY_ANT_H_
#define CPP_ANTSCOLONY_ANT_H_

#include <string>
#include <vector>
#include <ant_hill/AntHill.h>
#include <environment/Environment.h>
#include "../AntState.h"

using namespace std;

class Ant {
private:
    int age;
    int posX;
    int posY;
    Environment environment;
    AntState antState;
    AntHill antHill;

public:
    Ant(AntHill antHill, Environment environment)
            : posX(antHill.getPosX()), posY(antHill.getPosY()), age(0), antHill(antHill), environment(environment) {};

    //explicit Ant(const AntState &state, AntHill antHill, Environment environment) : posX(0), posY(0), antState(state), antHill(antHill), environment(environment) {};
    void setState(const AntState &);

    int getPosX() { return posX; }

    int getPosY() { return posY; }

    void moveLeft() { if (posX > 0) posX--; }

    void moveRight() { if (posX < environment.getWidth()) posX++; }

    void moveTop() { if (posX < environment.getHeight()) posY++; }

    void moveBottom() { if (posY > 0) posY--; }

    virtual void speak();

    virtual void evolve() = 0;
};

#endif  // CPP_ANTSCOLONY_ANT_H_
