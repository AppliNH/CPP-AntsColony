#include <iostream>
#include "Environment.h"

Environment::Environment(const int &height, const int &width, const int &foodCount, const int &obstacleCount,
                         AntHill *antHill)
        : height(height), width(width) {
    // Reset the random generator
    srand(time(NULL));
    // Build the grid
    buildGrid(width, height);
    //Insert the first ant hill
    antHills.push_back(antHill);
    grid.at(antHill->getPosY()).at(antHill->getPosX()) = antHill;
    // Insert the food
    insertFoods(foodCount);
    // Insert the obstacles
    insertObstacles(obstacleCount);
}


void Environment::displayStatus() {
    int foodCount = 0;
    int pheromoneCount = 0;
    int obstacleCount = 0;
    for (auto &line: grid) {
        for (auto &square: line) {
            if (square != nullptr && dynamic_cast<Food *>(square)) {
                foodCount++;
            }
            if (square != nullptr && dynamic_cast<Obstacle *>(square)) {
                obstacleCount++;
            }
            if (square != nullptr && dynamic_cast<Pheromone *>(square)) {
                pheromoneCount++;
            }
        }

    }
    cout << "## ENVIRONMENT ##" << endl;
    cout << "Foods : " << foodCount << endl;
    cout << "Obstacles : " << obstacleCount << endl;
    cout << "Pheromones : " << pheromoneCount << endl;
}

void Environment::deleteSquareBox(const int &posX, const int &posY) {
    if (grid.at(posY).at(posX) != nullptr) {
        delete grid.at(posY).at(posX);
        grid.at(posY).at(posX) = nullptr;
    }
}

void Environment::insertPheromone(const int &posX, const int &posY) {
    if (grid.at(posY).at(posX) == nullptr) {
        auto *p = new Pheromone(posX, posY, 10.0);
        grid.at(posY).at(posX) = p;
        pheromones.push_back(*p);
    } else if (auto *p = dynamic_cast<Pheromone *>(grid.at(posY).at(posX))) {
        p->increasePowerness();
    }
}

Environment::~Environment() {
    for (auto &l : grid) {
        for (auto c : l) {
            delete c;
        }
    }
    grid.clear();
}

void Environment::pheromoneDecay() {
    for (auto &p : pheromones) {
        if (p.decreasePowerness()) {
            deleteSquareBox(p.getPosX(), p.getPosY());
        }
    }

}

vector<AntHill *> Environment::getAntHills() {
    return antHills;
}

void Environment::buildGrid(const int &w, const int &h) {
    for (int row = 0; row < h; ++row) {
        vector<SquareBox *> line;
        line.reserve(w);
        for (int column = 0; column < w; ++column) {
            line.push_back(nullptr);
        }
        grid.push_back(line);
    }
}

void Environment::insertFoods(const int &foodCount) {
    if (!grid.empty()) {
        for (int i = 0; i < foodCount; ++i) {
            bool foodPlaced = false;
            while (!foodPlaced) {
                int foodPosX = rand() % width;
                int foodPosY = rand() % height;
                if (grid.at(foodPosY).at(foodPosX) == nullptr) {
                    grid.at(foodPosY).at(foodPosX) = new Food(foodPosX, foodPosY);
                    foodPlaced = true;
                }
            }

        }
    }
}

void Environment::insertObstacles(const int &obstacleCount) {
    if (!grid.empty()) {
        for (int i = 0; i < obstacleCount; ++i) {
            bool obstaclePlaced = false;
            while (!obstaclePlaced) {
                int obstaclePosX = rand() % width;
                int obstaclePosY = rand() % height;
                if (grid.at(obstaclePosY).at(obstaclePosX) == nullptr) {
                    grid.at(obstaclePosY).at(obstaclePosX) = new Obstacle(obstaclePosX, obstaclePosY);
                    obstaclePlaced = true;
                }
            }

        }
    }
}

void Environment::getEmptySquareBox(int &posX, int &posY) {
    bool found = false;
    while (!found) {
        posX = rand() % width;
        posY = rand() % height;
        if (grid.at(posY).at(posX) == nullptr) {
            found = true;
        }
    }
}

void Environment::addAntHill(AntHill *antHill) {
    antHills.push_back(antHill);
    grid.at(antHill->getPosY()).at(antHill->getPosX()) = antHill;
}

int Environment::getWidth() const { return width; }

int Environment::getHeight() const { return height; }

vector<vector<SquareBox *>> Environment::getGrid() { return grid; }

