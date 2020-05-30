#include "Environment.h"

bool Environment::isCrossable(const int &posX, const int &posY) {

}

vector<SquareBox> Environment::analyzeEnv(const int &posX, const int &posY) {

    auto up1 = posY + 1 > height ? nullptr : new SquareBox(posX, posY+1);
    auto up2 = posY + 2 > height ? nullptr :new SquareBox(posX, posY +2);

    auto down1 = posY - 1 < 0 ? nullptr : new SquareBox(posX, posY-1);
    auto down2 = posY - 2 < 0 ? nullptr :new SquareBox(posX, posY -2);

    auto right1 = posX + 1 > width ? nullptr : new SquareBox(posX+1, posY);
    auto right2 = posX + 2 > width ? nullptr : new SquareBox(posX+2, posY);

    auto left1 = posX - 1 < 0 ? nullptr : new SquareBox(posX-1, posY);
    auto left2 = posX - 2 < 0 ? nullptr : new SquareBox(posX-2, posY);
    vector<SquareBox> localEnv;

    auto glambda = [](auto square, vector<SquareBox> *localEnv) { square != nullptr ? localEnv->push_back(square) : nullptr; };
    //glambda(up1, localEnv);
    //glambda(up2, localEnv);
    //glambda(down1, localEnv);
    //glambda(down2, localEnv);
    //glambda(right1, localEnv);






}
