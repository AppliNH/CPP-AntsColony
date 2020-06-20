#include "AntEgg.h"

void AntEgg::speak() {
    Ant::speak();
    cout << "and an Egg" << endl;
}

Ant * AntEgg::evolve() {
    return new AntWorker(antHill, environment);
}
