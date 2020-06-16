#include "ants/ant_worker/AntWorker.h"
#include "game/Game.h"

int main() {
    Game myGame = Game(2, 10, 10, 10, 5);
    myGame.start();
    return 0;
}
