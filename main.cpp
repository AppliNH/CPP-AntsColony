#include "ants/ant_worker/AntWorker.h"
#include "game/Game.h"

int main() {
    Game myGame = Game(30, 30, 20, 80, 100);
    myGame.start();
    return 0;

}
