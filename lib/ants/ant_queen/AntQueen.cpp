#include "AntQueen.h"


void AntQueen::speak() {
    LivingAnt::speak();
    cout << "(Queen)" << endl;
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

void AntQueen::displayState() {
    cout << "at_home";
}

