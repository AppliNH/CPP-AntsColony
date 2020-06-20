#include "AntEgg.h"

void AntEgg::speak() {
    Ant::speak();
    cout << "and an Egg" << endl;
}

LivingAnt * AntEgg::evolve() {
    return new AntWorker(antHill, environment, willBeQueen);
}
