#include "ants/ant_worker/AntWorker.h"
#include "game/Game.h"

int main() {
    Game myGame = Game(6, 4, 50, 20, 20, 30, 30);
    myGame.start();
    return 0;

}
