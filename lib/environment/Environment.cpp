#include "Environment.h"

bool Environment::isCrossable(const int &posX, const int &posY) {

}

vector<vector<SquareBox>> Environment::analyzeEnv(const int &posX, const int &posY) {
    // search matching positions in foods pheromones & obstacles

    auto up1 = posY + 1 > height ? nullptr : new SquareBox(posX, posY + 1);
    auto up2 = posY + 2 > height ? nullptr : new SquareBox(posX, posY + 2);

    auto down1 = posY - 1 < 0 ? nullptr : new SquareBox(posX, posY - 1);
    auto down2 = posY - 2 < 0 ? nullptr : new SquareBox(posX, posY - 2);

    auto right1 = posX + 1 > width ? nullptr : new SquareBox(posX + 1, posY);
    auto right2 = posX + 2 > width ? nullptr : new SquareBox(posX + 2, posY);

    auto left1 = posX - 1 < 0 ? nullptr : new SquareBox(posX - 1, posY);
    auto left2 = posX - 2 < 0 ? nullptr : new SquareBox(posX - 2, posY);

    vector<SquareBox> localEnv;

    auto lambda_1{[](auto square, vector<SquareBox> &local) -> void {
        if (square != nullptr)
            local.push_back(static_cast<SquareBox>(*square));
    }};

    lambda_1(up1, localEnv);
    lambda_1(up2, localEnv);

    lambda_1(down1, localEnv);
    lambda_1(down2, localEnv);

    lambda_1(right1, localEnv);
    lambda_1(right2, localEnv);

    lambda_1(left1, localEnv);
    lambda_1(left2, localEnv);

    vector<SquareBox> foundFood;
    vector<SquareBox> foundPhero;
    vector<SquareBox> foundObstacles;


    auto lambda_search{[localEnv](vector<SquareBox *> collection, vector<SquareBox> &foundCollection) -> void {
        for (int i = 0; i < collection.size(); ++i) {
            for (int j = 0; j < localEnv.size(); ++j) {
                if (*collection[i] == localEnv[j]) {
                    foundCollection.push_back(localEnv[j]);
                }

            }
        }
    }};

    vector<SquareBox*> foodCollection(foods.begin(), foods.end());
    vector<SquareBox*> pheroCollection(pheromones.begin(), pheromones.end());
    vector<SquareBox*> obsCollection(obstacles.begin(), obstacles.end());

    lambda_search(foodCollection, foundFood);
    lambda_search(pheroCollection, foundPhero);
    lambda_search(obsCollection, foundObstacles);

    vector<vector<SquareBox>> resVector;
    resVector.push_back(foundFood);
    resVector.push_back(foundPhero);
    resVector.push_back(foundObstacles);


    return resVector;


}
