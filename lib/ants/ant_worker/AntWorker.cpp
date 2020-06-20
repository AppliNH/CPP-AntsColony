#include "AntWorker.h"

void AntWorker::speak() {
    LivingAnt::speak();
    cout << "(Worker)" << endl;
}

LivingAnt *AntWorker::evolve() {
    return new AntWarrior(antHill, environment, willBeQueen);
}

