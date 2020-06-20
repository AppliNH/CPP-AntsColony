#include "AntYoungQueen.h"


void AntYoungQueen::speak() {
    LivingAnt::speak();
    cout << "(Ant young queen)" << endl;
}


bool AntYoungQueen::isRequiredToEat() {
    return antHill.getFoodCount() >= foodConsumed;
}

void AntYoungQueen::eatFood() {
    for (int i = 0; i < foodConsumed; ++i) {
        antHill.eatFromStock();
    }
    lifePoints++;
}