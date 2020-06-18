#include "AntWarrior.h"

void AntWarrior::speak() {
    LivingAnt::speak();
    cout << "(Warrior)" << endl;
}

void AntWarrior::evolve() {
    cout << "Evolve to queen" << endl;
}

void AntWarrior::attack(LivingAnt &livingAnt) {
    if(!livingAnt.isSameAntHill(antHill)) {
        livingAnt.undergoDamage();
        cout << "ATTACKING" << endl;
    }
    cout << "NOT ATTACKING" << endl;
}