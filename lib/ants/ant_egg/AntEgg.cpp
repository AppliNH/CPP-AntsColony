#include "AntEgg.h"

void AntEgg::speak() {
    Ant::speak();
    cout << "and an Egg" << endl;
}

void AntEgg::evolve() {
    cout << "Evolve to a worker" << endl;
}
