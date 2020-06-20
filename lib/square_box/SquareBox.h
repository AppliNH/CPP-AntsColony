#ifndef CPP_ANTSCOLONY_SQUAREBOX_H
#define CPP_ANTSCOLONY_SQUAREBOX_H


class SquareBox {

protected:
    int posX;
    int posY;
public:
    SquareBox(int X, int Y) : posX(X), posY(Y) {}

    virtual ~SquareBox() = default;

    [[nodiscard]] int getPosX() const { return posX; }

    [[nodiscard]] int getPosY() const { return posY; }

    bool operator==(const SquareBox &squareBox) const {
        return posX == squareBox.posX && posY == squareBox.posY;
    };

};


#endif //CPP_ANTSCOLONY_SQUAREBOX_H
