#include <iostream>
#include "Ant.h"

using namespace std;


void Ant::move(const string& direction) {
    if (direction == "Y")
        this->posY++;
    if (direction == "X")
        this->posX++;
}

bool Ant::collectFood(const Food food) {
    if (carriedFood.size() < maxCarriedFood) {
        this->carriedFood.push_back(food);
        return true;
    }
    return false;
}

void Ant::dieSlowly() {
    this->lifePoints--;
}

void Ant::eat(const Food food) {
    this->lifePoints++;
}

bool Ant::isRequiredToEat() const {

    return this->lifePoints < this->lifeThreshold;

}

void Ant::displayAnt() const {
    cout << this->lifePoints << endl;

}

Ant::Ant(int lifePoints, int lifeThreshold, int maxCarriedFood) : posX(0), posY(0), lifePoints(lifePoints),
                                                                  lifeThreshold(lifeThreshold),
                                                                  maxCarriedFood(maxCarriedFood) {

}
