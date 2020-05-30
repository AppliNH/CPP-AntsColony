//
// Created by Thomas Martin on 30/05/2020.
//

#ifndef CPP_ANTSCOLONY_GAME_H
#define CPP_ANTSCOLONY_GAME_H


#include <environment/Environment.h>

class Game {
    int round;
    Environment* environment;

public:
    Game() {}
    void moveAllAnts();
    void createPheromons();


};


#endif //CPP_ANTSCOLONY_GAME_H
