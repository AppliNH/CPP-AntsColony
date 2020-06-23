#ifndef CPP_ANTSCOLONY_LIB_FOOD_H_
#define CPP_ANTSCOLONY_LIB_FOOD_H_

#include <square_box/SquareBox.h>

class Food : public SquareBox {

private:
    int size = 10;
public:
    Food(int X, int Y) : SquareBox(X, Y) {}

    ~Food() override = default;

    [[nodiscard]] int getSize() const;

    void grabFood();
};

#endif  // CPP_ANTSCOLONY_LIB_FOOD_H_