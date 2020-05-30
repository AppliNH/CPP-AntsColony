#include "AntWarrior.h"

void AntWarrior::speak() {
    LivingAnt::speak();
    cout << "and a Warrior" << endl;
}

void AntWarrior::evolve() {
    cout << "Evolve to queen" << endl;
}
