#include <iostream>
#include <ants/ant_worker/AntWorker.h>
#include <ants/ant_warrior/AntWarrior.h>
#include <ants/ant_egg/AntEgg.h>
#include <game/Game.h>
#include "ants/ant_queen/AntQueen.h"

int main() {
    Game myGame = Game(10, 10, 6, 4, 20, 50, 0);
    myGame.start();
    return 0;

}
