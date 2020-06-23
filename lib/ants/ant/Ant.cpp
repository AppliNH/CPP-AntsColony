#include <iostream>
#include "Ant.h"

AntHill &Ant::getAntHill()
    { return antHill; }

bool Ant::grow()  {
    age++;
    return age == ageToEvolve;
}

bool Ant::isAtHome()  { return posX == antHill.getPosX() && posY == antHill.getPosY(); }

