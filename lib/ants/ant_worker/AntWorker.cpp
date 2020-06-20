#include "AntWorker.h"

void AntWorker::speak() {
    LivingAnt::speak();
    cout << "(Worker)" << endl;
}

Ant * AntWorker::evolve() {
    return new AntWarrior(antHill, environment);
}

