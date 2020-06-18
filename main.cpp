#include "ants/ant_worker/AntWorker.h"
#include "game/Game.h"

int main() {
    Game myGame = Game(4, 10, 10, 2, 5);
    myGame.start();
    return 0;
}
