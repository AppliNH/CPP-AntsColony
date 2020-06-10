#include "AntWorker.h"

void AntWorker::speak() {
    LivingAnt::speak();
    cout << "and a Worker" << endl;
}

void AntWorker::evolve() {
    cout << "Evolve to warrior" << endl;
}

void AntWorker::move(char direction) {
    LivingAnt::move(direction);
}