#include "AntHill.h"

AntHill::~AntHill() {

}

void AntHill::stockFood(const Food &food) {
    foodStock.push_back(new Food(food.getPosX(), food.getPosY()));
}

void AntHill::status() {
    cout << "## ANT_HILL ##" << endl;
    cout << "Stored food : " << foodStock.size() << endl;
}
