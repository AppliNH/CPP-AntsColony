#include <iostream>
#include <ants/ant_worker/AntWorker.h>
#include <ants/ant_warrior/AntWarrior.h>
#include <ants/ant_egg/AntEgg.h>
#include <game/Game.h>
#include "ants/ant_queen/AntQueen.h"

int main() {
    Game *myGame = new Game(100,100,50,50,20,20);
    myGame->start();
    /*AntQueen queen;
    AntWorker worker;
    AntWarrior warrior;
    AntEgg egg(AntHill(0, 0, 0, 0));
    Environment environment(100, 100);

    egg.speak();
    queen.speak();
    worker.speak();
    warrior.speak();*/

    return 0;

}
