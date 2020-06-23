#ifndef CPP_ANTSCOLONY_SQUAREBOX_H
#define CPP_ANTSCOLONY_SQUAREBOX_H


class SquareBox {

protected:
    int posX;
    int posY;
public:
    SquareBox(int X, int Y) : posX(X), posY(Y) {}

    virtual ~SquareBox() = default;

    [[nodiscard]] int getPosX() const;

    [[nodiscard]] int getPosY() const;

    bool operator==(const SquareBox &squareBox) const;

};


#endif //CPP_ANTSCOLONY_SQUAREBOX_H
