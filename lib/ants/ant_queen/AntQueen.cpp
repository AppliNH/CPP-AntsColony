#include "AntQueen.h"


void AntQueen::speak() {
    LivingAnt::speak();
    cout << "and a Queen" << endl;
}

void AntQueen::evolve() {
    cout << "Evolve to nothing" << endl;
}

