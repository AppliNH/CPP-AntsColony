#include "AntEgg.h"

void AntEgg::speak() {
    cout << "(Egg)" << endl;
}

LivingAnt *AntEgg::evolve() {
    return new AntWorker(antHill, environment, willBeQueen);
}
