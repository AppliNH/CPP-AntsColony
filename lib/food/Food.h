#ifndef CPP_ANTSCOLONY_LIB_FOOD_H_
#define CPP_ANTSCOLONY_LIB_FOOD_H_

#include <square_box/SquareBox.h>

class Food : public SquareBox {

private:
    int size;
public:
    Food(int X, int Y) : SquareBox(X, Y), size(15) {}

    ~Food() override = default;

    int getSize() { return size; }

    void grabFood() { size -= 1; }
};

#endif  // CPP_ANTSCOLONY_LIB_FOOD_H_