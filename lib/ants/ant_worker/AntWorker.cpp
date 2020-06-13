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

bool AntWorker::dieSlowly(const int &round) {
    if (round % 20 == 1) {
        return LivingAnt::looseLife();
    } return false;
}
