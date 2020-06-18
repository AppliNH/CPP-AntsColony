#include "ants/ant_worker/AntWorker.h"
#include "game/Game.h"

int main() {
    Game myGame = Game(10, 20, 10, 30, 5);
    myGame.start();
    return 0;
}
