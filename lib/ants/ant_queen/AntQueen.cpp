#include "AntQueen.h"


void AntQueen::speak() {
    LivingAnt::speak();
    cout << "(Queen)" << endl;
}

void AntQueen::move(char direction) {

}

Ant * AntQueen::evolve() {
    cout << "Evolve to nothing" << endl;
}

bool AntQueen::isRequiredToEat() {
    return antHill.getFoodCount() >= foodConsumed;
}

void AntQueen::eatFood() {
    for (int i = 0; i < foodConsumed; ++i) {
        antHill.eatFromStock();
    }
    lifePoints++;
}

