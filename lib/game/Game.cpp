//
// Created by Thomas Martin on 30/05/2020.
//

#include "Game.h"

void Game::moveAllAnts() {
    for (int i = 0; i < livingAnts.size() ; ++i) {
        livingAnts[i]->move('Y');


    }
}
