//
// Created by Thomas Martin on 30/05/2020.
//

#ifndef CPP_ANTSCOLONY_SQUAREBOX_H
#define CPP_ANTSCOLONY_SQUAREBOX_H


class SquareBox {

protected:
    int posX;
    int posY;
public:
    SquareBox(int X, int Y) : posX(X), posY(Y) {}

    int getPosX() { return posX;}
    int getPosY() { return posY;}

    bool operator==(const SquareBox&);

};





#endif //CPP_ANTSCOLONY_SQUAREBOX_H
