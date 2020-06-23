#include "AntHill.h"

AntHill::~AntHill() {
    for (auto &f : foodStock) {
        delete f;
    }
    foodStock.clear();
}

void AntHill::stockFood(const Food &food) {
    if (foodStock.size() < maxFood) {
        foodStock.push_back(new Food(food.getPosX(), food.getPosY()));
    }
}

void AntHill::displayStatus() {
    cout << "## ANT_HILL ##" << endl;
    cout << "   Stored food : " << foodStock.size() << endl;
}

int AntHill::getFoodCount() { return foodStock.size(); }

int AntHill::getMaxPopulation() const { return maxPopulation; }

void AntHill::eatFromStock() { foodStock.erase(foodStock.begin()); }

