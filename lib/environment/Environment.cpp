#include <iostream>
#include "Environment.h"

Environment::Environment(int h, int w, int foodCount, int obstacleCount) : height(h), width(w) {
    for (int row = 0; row < h; ++row) {
        vector<SquareBox *> line;
        line.reserve(w);
        for (int column = 0; column < w; ++column) {
            line.push_back(nullptr);
        }
        grid.push_back(line);
    }

    grid.at(7).at(3) = new Food(3, 7);
    grid.at(4).at(1) = new Food(1, 4);
    grid.at(5).at(10) = new Food(10, 5);

    grid.at(1).at(15) = new Obstacle(15, 1);
    grid.at(2).at(15) = new Obstacle(15, 2);
    grid.at(3).at(15) = new Obstacle(15, 3);
    grid.at(4).at(15) = new Obstacle(15, 4);
    grid.at(5).at(15) = new Obstacle(15, 5);

    grid.at(7).at(27) = new Obstacle(4, 27);
    grid.at(7).at(28) = new Obstacle(4, 28);
    grid.at(7).at(29) = new Obstacle(4, 29);
    grid.at(7).at(30) = new Obstacle(4, 30);
    grid.at(7).at(31) = new Obstacle(4, 31);


}

char Environment::analyzeEnv(const int &posX, const int &posY) {
    // search matching positions in foods pheromones & obstacles

    char newDirection = ' ';

    auto up1 = posY + 1 > height ? nullptr : new SquareBox(posX, posY + 1);
    //auto up2 = posY + 2 > height ? nullptr : new SquareBox(posX, posY + 2);

    auto down1 = posY - 1 < 0 ? nullptr : new SquareBox(posX, posY - 1);
    //auto down2 = posY - 2 < 0 ? nullptr : new SquareBox(posX, posY - 2);

    auto right1 = posX + 1 > width ? nullptr : new SquareBox(posX + 1, posY);

    //auto right2 = posX + 2 > width ? nullptr : new SquareBox(posX + 2, posY);

    auto left1 = posX - 1 < 0 ? nullptr : new SquareBox(posX - 1, posY);
    //auto left2 = posX - 2 < 0 ? nullptr : new SquareBox(posX - 2, posY);

    vector<SquareBox> localEnv;

    auto lambda_1{[](auto square, vector<SquareBox> &local) -> void {
        if (square != nullptr)
            local.push_back(static_cast<SquareBox>(*square));
    }};

    lambda_1(up1, localEnv);
    //lambda_1(up2, localEnv);

    lambda_1(down1, localEnv);
    //lambda_1(down2, localEnv);

    lambda_1(right1, localEnv);
    //lambda_1(right2, localEnv);

    lambda_1(left1, localEnv);
    //lambda_1(left2, localEnv);

    vector<SquareBox> foundFood;
    vector<SquareBox> foundPhero;
    vector<SquareBox> foundObstacles;


    auto lambda_search{[localEnv, posX, posY, &newDirection](vector<SquareBox *> collection,
                                                             vector<SquareBox> &foundCollection) -> void {

        for (auto itCollection = collection.begin(); itCollection < collection.end(); ++itCollection) {
            if (posX == (*itCollection)->getPosX() && posY == (*itCollection)->getPosY()) {
                cout << "GRAAAAABBB" << endl;
                collection.erase(itCollection);
                break;
            }
            for (auto j : localEnv) {
                if (**itCollection == j) {
                    foundCollection.push_back(j);
                    if (posX != (*itCollection)->getPosX()) {
                        if (posX - (*itCollection)->getPosX() < 0) {
                            cout << "    ==> Toward R ";
                            newDirection = 'R';
                        } else {
                            cout << "   ==> Toward L ";
                            newDirection = 'L';
                        }
                    } else if (posY != (*itCollection)->getPosY()) {
                        if (posY - (*itCollection)->getPosY() < 0) {
                            cout << "   ==> Toward T ";
                            newDirection = 'T';
                        } else {
                            cout << "   ==> Toward B ";
                            newDirection = 'B';
                        }
                    }
                    cout << "Something around !" << endl;
                }

            }
        }
    }};

    vector<SquareBox *> foodCollection(foods.begin(), foods.end());
    vector<SquareBox *> pheroCollection(pheromones.begin(), pheromones.end());
    vector<SquareBox *> obsCollection(obstacles.begin(), obstacles.end());

    lambda_search(foodCollection, foundFood);
    lambda_search(pheroCollection, foundPhero);
    lambda_search(obsCollection, foundObstacles);

    vector<vector<SquareBox>> resVector;
    resVector.push_back(foundFood);
    resVector.push_back(foundPhero);
    resVector.push_back(foundObstacles);

    return newDirection;


}

void Environment::status() {
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
        }

    }
    cout << "## ENVIRONMENT ##" << endl;
    cout << "Food left : " << foodCount << endl;
    cout << "Obstacles : " << obstacleCount << endl;
    displayGrid();
}

void Environment::deleteSquareBox(const int &posX, const int &posY) {
    if (grid.at(posY).at(posX) != nullptr) {
        delete grid.at(posY).at(posX);
        grid.at(posY).at(posX) = nullptr;
    }
}

void Environment::insertPheromone(const int &posX, const int &posY) {
    if (grid.at(posY).at(posX) == nullptr) {
        grid.at(posY).at(posX) = new Pheromone(posX, posY, 10);
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

SquareBox *Environment::getSquareBoxAt(const int &posX, const int &posY) {
    if (grid.at(posY).at(posX) != nullptr) {
        return grid.at(posY).at(posX);
    }
    return nullptr;
}

void Environment::displayGrid() {
    for (int row = 0; row < height; ++row) {
        for (int column = 0; column < width; ++column) {
            if (dynamic_cast<Pheromone *>(grid.at(row).at(column))) {
                cout << "|P";
            } else if (dynamic_cast<Food *>(grid.at(row).at(column))) {
                cout << "|F";
            } else if (dynamic_cast<Obstacle *>(grid.at(row).at(column))) {
                cout << "|X";
            } else {
                cout << "|_";
            }
        }
        cout << "|" << endl;
    }
}
