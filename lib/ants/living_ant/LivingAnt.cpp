#include <iostream>
#include "LivingAnt.h"

void LivingAnt::speak() {
    cout << "(X:"  << getPosX() << ", Y:" << getPosY() << ", food: " << carriedFood.size() << ") I'm a living ant ";
}

void LivingAnt::move(char pos) {
    switch (pos) {
        case 'L':
            moveLeft();
            break;
        case 'R':
            moveRight();
            break;
        case 'T':
            moveTop();
            break;
        case 'B':
            moveBottom();
            break;
    }
}
