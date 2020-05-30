#include "Environment.h"

bool Environment::isCrossable(const int &posX, const int &posY) {

}

Environment::~Environment() {
    for (auto p : obstacles) {
        delete p;
    }
    obstacles.clear();
    for (auto p : foods) {
        delete p;
    }
    foods.clear();
    for (auto p : pheromones) {
        delete p;
    }
    pheromones.clear();
}
