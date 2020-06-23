#include "Pheromone.h"

bool Pheromone::decreasePowerness() {
    powerness -= decayRate;
    return powerness <= 0;
}

void Pheromone::increasePowerness() { powerness++; }
