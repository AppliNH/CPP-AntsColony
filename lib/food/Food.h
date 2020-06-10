#ifndef CPP_ANTSCOLONY_LIB_FOOD_H_
#define CPP_ANTSCOLONY_LIB_FOOD_H_

#include <square_box/SquareBox.h>

class Food : public SquareBox {

public:
    Food(int X, int Y) : SquareBox(X, Y) {}
    ~Food() override= default;
};

#endif  // CPP_ANTSCOLONY_LIB_FOOD_H_