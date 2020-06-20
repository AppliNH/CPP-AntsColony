#include <iostream>
#include "LivingAnt.h"

void LivingAnt::speak() {
    cout << "(";
    displayPosition();
    cout << ", ";
    displayState();
    cout << ", ";
    displayLifePoints();
    cout << ", ";
    cout << "carriedFood: " << carriedFood.size() << ") Living ant ";
}

void LivingAnt::move(char pos) {
    switch (pos) {
        case 'L':
            moveLeft();
            break;
        case 'R':
            moveRight();
            break;
        case 'T':
            moveTop();
            break;
        case 'B':
            moveBottom();
            break;
        default:
            break;
    }
    if (isFullOfFood()) {
        environment.insertPheromone(posX, posY);
    }
}

bool LivingAnt::isFullOfFood() {
    return (carriedFood.size() == maxCarriedFood);
}

void LivingAnt::layDownFoodInAntHill() {
    for (auto &food : carriedFood) {
        getAntHill().stockFood(*food);
    }
    carriedFood.clear();
}

LivingAnt::~LivingAnt() {
    for (auto f : carriedFood) {
        delete f;
    }
    carriedFood.clear();
}

void LivingAnt::displayPosition() {
    cout << "X:" << getPosX() << " Y:" << getPosY();
}

void LivingAnt::displayLifePoints() const {
    cout << "Health : " << lifePoints << " (" << lifeThreshold << ")";
    /*for (int i = 0; i < lifePoints; ++i) {
        if (i <= lifeThreshold) {
            cout << "#";
        } else {
        cout << "|";

        }
    }*/
}

void LivingAnt::displayState() {
    string state(isAtHome() ? "at_home" : !isFullOfFood() ? "looking_for_food" : "comeback_home");
    cout << state;
}

bool LivingAnt::grabFood(const Food &food) {
    if (isRequiredToEat()) {
        eatFood();
    }
    if (!isFullOfFood()) {
        storeFood(food);
        return true;
    } else {
        return false;
    }
}

void LivingAnt::eatFood() {
    for (int i = 0; i < foodConsumed; ++i) {
        carriedFood.erase(carriedFood.begin());
    }
    lifePoints++;
}

void LivingAnt::storeFood(const Food &food) {
    carriedFood.push_back(new Food(food.getPosX(), food.getPosY()));
}

bool LivingAnt::isRequiredToEat() {
    return lifePoints <= lifeThreshold && !carriedFood.empty() && carriedFood.size() >= foodConsumed;
}

bool LivingAnt::looseLife()  {
    lifePoints -= decayRate;
    return lifePoints <= 0;
}

Ant *LivingAnt::evolve() {
    return this;
}
