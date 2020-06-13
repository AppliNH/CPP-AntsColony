#include <iostream>
#include "LivingAnt.h"

void LivingAnt::speak() {
    cout << "(";
    displayPosition();
    cout << ", \t";
    displayState();
    cout << ", ";
    displayLifePoints();
    cout << ", ";
    cout << "carriedFood: " << carriedFood.size() << ") I'm a living ant ";
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
    environment.insertPheromone(posX, posY);
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

LivingAnt::~LivingAnt() {
    for (auto f : carriedFood) {
        delete f;
    }
    carriedFood.clear();
}

void LivingAnt::displayPosition() {
    cout << "X:" << getPosX() << " Y:" << getPosY();
}

void LivingAnt::displayLifePoints() {
    cout << "Health :";
    for (int i = 0; i < lifePoints; ++i) {
        cout << "|";
    }
}

void LivingAnt::displayState() {
    string state(isAtHome() ? "at_home" : !isFullOfFood() ? "looking_for_food" : "comeback_home");
    cout << state;
}
