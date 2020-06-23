#include "SquareBox.h"

bool SquareBox::operator==(const SquareBox &squareBox) const {
    return posX == squareBox.posX && posY == squareBox.posY;
}

int SquareBox::getPosY() const { return posY; }

int SquareBox::getPosX() const { return posX; }
