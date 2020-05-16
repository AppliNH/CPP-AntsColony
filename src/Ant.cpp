#include <iostream>
#include "../headers/Ant.h"

using namespace std;

Ant::Ant(int lifePoints, int lifeThreshold, int maxCarriedFood) 
    : posX(0), posY(0), lifePoints(lifePoints), lifeThreshold(lifeThreshold), maxCarriedFood(maxCarriedFood) {}

void Ant::move(string direction)
{
    if (direction == "Y")
        this->posY++;
    if (direction == "X")
        this->posX++;
}

bool Ant::collectFood(const Food food)
{
    if (carriedFood.size() < maxCarriedFood)
    {
        this->carriedFood.push_back(food);
        return true;
    }
    return false;
}

void Ant::dieSlowly()
{
    this->lifePoints--;
}

void Ant::eat(const Food food) {
    this->lifePoints++;
}

bool Ant::isRequiredToEat()
{

    if (this->lifePoints < this->lifeThreshold)
        return true;

    return false;
}
void Ant::displayAnt() {
    cout << this->lifePoints << endl;
    
}