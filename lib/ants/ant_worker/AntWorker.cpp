#include "AntWorker.h"

void AntWorker::speak() {
    LivingAnt::speak();
    cout << "(Worker)" << endl;
}

void AntWorker::evolve() {
    cout << "Evolve to warrior" << endl;
}

