#include "AntWarrior.h"

void AntWarrior::speak() {
    LivingAnt::speak();
    cout << "(Warrior)" << endl;
}

void AntWarrior::evolve() {
    cout << "Evolve to queen" << endl;
}

