#include "AntWarrior.h"

void AntWarrior::speak() {
    LivingAnt::speak();
    cout << "and a Warrior" << endl;
}

void AntWarrior::evolve() {
    cout << "Evolve to queen" << endl;
}

void AntWarrior::move(char direction) {
    LivingAnt::move(direction);
}

bool AntWarrior::dieSlowly(const int &round) {
    if (LivingAnt::isRequiredToEat()) {
        LivingAnt::eatFood();
    }
    if (round % 15 == 1) {
        return LivingAnt::looseLife();
    } return false;
}
