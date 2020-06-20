#ifndef CPP_ANTSCOLONY_SQUAREBOX_H
#define CPP_ANTSCOLONY_SQUAREBOX_H


class SquareBox {

protected:
    int posX;
    int posY;
public:
    SquareBox(int X, int Y) : posX(X), posY(Y) {}
    virtual ~SquareBox();

    virtual int getPosX() const { return posX;}
    virtual int getPosY() const { return posY;}

    bool operator==(const SquareBox&);

};





#endif //CPP_ANTSCOLONY_SQUAREBOX_H
