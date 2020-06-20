#include "AntWarrior.h"

void AntWarrior::speak() {
    LivingAnt::speak();
    cout << "(Warrior)" << endl;
}

Ant * AntWarrior::evolve() {
    if (willBeQueen) {
        return new AntYoungQueen(antHill, environment, 0, 0);
    } else {
        return this;
    }
}

void AntWarrior::attack(LivingAnt &livingAnt) {
    if(!livingAnt.isSameAntHill(antHill)) {
        livingAnt.undergoDamage();
        cout << "ATTACKING" << endl;
    }
    cout << "NOT ATTACKING" << endl;
}