#include "ants/ant_worker/AntWorker.h"
#include "game/Game.h"

int main() {
    Game myGame = Game(5, 10, 10, 15, 10);
    myGame.start();
    return 0;
}
