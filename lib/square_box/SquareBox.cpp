//
// Created by Thomas Martin on 30/05/2020.
//

#include "SquareBox.h"

bool SquareBox::operator==(const SquareBox &squareBox) {
    return posX == squareBox.posX && posY == squareBox.posY;
}
