#include <iostream>
#include "Ant.h"

void Ant::speak() {
    cout << "I'm an ant ";
}

void Ant::setState(const AntState &state) {
    antState = state;
}

Ant::Ant() {

}
