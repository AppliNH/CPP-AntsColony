#include <iostream>
#include "Environment.h"

Environment::Environment(int h, int w)  : height(h), width(w) {

    for (int row = 0; row < h; ++row) {
        vector<SquareBox *> line;
        if (row % 2 == 0) {
            for (int column = 0; column < w; ++column) {
                if (column % 2 == 0) {
                    line.push_back(new Food(column, row));
                } else {
                    line.push_back(nullptr);
                }
            }
        } else {
            for (int column = 0; column < w; ++column) {
                if (column % 2 != 0) {
                    line.push_back(new Obstacle(column, row));
                } else {
                    line.push_back(nullptr);
                }
            }
        }
        grid.push_back(line);

    }
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
    cout << "## ENV ##" << endl;
    cout << "Food : " << foodCount << endl;
    cout << "Obstacles : " << obstacleCount << endl;
}

void Environment::deleteSquareBox(const int &posX, const int &posY) {
     if (grid.at(posY).at(posX) != nullptr) {
        delete grid.at(posY).at(posX);
        grid.at(posY).at(posX) = nullptr;
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
