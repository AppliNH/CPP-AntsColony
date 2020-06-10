#include <iostream>
#include "LivingAnt.h"

void LivingAnt::speak() {
    string state(isAtHome() ? "at_home" : !isFullOfFood() ? "looking_for_food" : "comeback_home");
    cout << "(X:" << getPosX() << ", Y:" << getPosY() << ", carriedFood: " << carriedFood.size() << ", " << state
         << ") I'm a living ant ";
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
    }
}

bool LivingAnt::collectFood(const Food &food) {
    if (!isFullOfFood()) {
        carriedFood.push_back(new Food(food.getPosX(), food.getPosY()));
        return true;
    } else {
        return false;
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
