#include "AntWorker.h"

void AntWorker::speak() {
    LivingAnt::speak();
    cout << "and a Worker" << endl;
}

void AntWorker::evolve() {
    cout << "Evolve to warrior" << endl;
}

bool AntWorker::dieSlowly(const int &round) {
    if (LivingAnt::isRequiredToEat()) {
        LivingAnt::eatFood();
    }
    if (round % 20 == 1) {
        return LivingAnt::looseLife();
    } return false;
}
