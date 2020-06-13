#include "AntQueen.h"


void AntQueen::speak() {
    LivingAnt::speak();
    cout << "and a Queen" << endl;
}

void AntQueen::evolve() {
    cout << "Evolve to nothing" << endl;
}

void AntQueen::move(char direction) {

}

bool AntQueen::dieSlowly(const int &round) {
    if (LivingAnt::isRequiredToEat()) {
        LivingAnt::eatFood();
    }
    if (round % 100 == 1) {
        return LivingAnt::looseLife();
    } return false;
}
