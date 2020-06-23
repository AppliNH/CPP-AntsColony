#include "AntWarrior.h"

void AntWarrior::speak() {
    LivingAnt::speak();
    cout << "(Warrior)" << endl;
}

LivingAnt *AntWarrior::evolve() {
    int antHillPosX;
    int antHillPosY;
    environment.getEmptySquareBox(antHillPosX, antHillPosY);
    return new AntYoungQueen(antHill, environment, antHillPosX, antHillPosY);
}

void AntWarrior::attack(LivingAnt &livingAnt) {
    if (livingAnt.getAntHill() != antHill) {
        livingAnt.undergoDamage();
        cout << "ATTACKING" << endl;
    }
    cout << "NOT ATTACKING" << endl;
}

bool AntWarrior::grow() {
    age++;
    return age == ageToEvolve && willBeQueen;
}
