#include "SquareBox.h"

bool SquareBox::operator==(const SquareBox &squareBox) const {
    return posX == squareBox.posX && posY == squareBox.posY;
}

int SquareBox::getPosY() const { return posY; }

int SquareBox::getPosX() const { return posX; }

bool SquareBox::operator!=(const SquareBox &squareBox) const {
    return posX != squareBox.posX || posY != squareBox.posY;
}

SquareBox::SquareBox(const int &posX, const int &posY): posX(posX), posY(posY) {
    texture.loadFromFile(imagePath);
}

sf::Texture SquareBox::getTexture() {
    return texture;
}
