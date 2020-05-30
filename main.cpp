#include <iostream>
#include <ants/ant_worker/AntWorker.h>
#include <ants/ant_warrior/AntWarrior.h>
#include <ants/ant_egg/AntEgg.h>
#include "ants/ant_queen/AntQueen.h"

int main() {
    AntQueen queen;
    AntWorker worker;
    AntWarrior warrior;
    AntEgg egg;

    egg.speak();
    queen.speak();
    worker.speak();
    warrior.speak();
    return 0;

}
