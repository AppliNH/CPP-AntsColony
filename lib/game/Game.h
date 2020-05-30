//
// Created by Thomas Martin on 30/05/2020.
//

#ifndef CPP_ANTSCOLONY_GAME_H
#define CPP_ANTSCOLONY_GAME_H


#include <environment/Environment.h>

class Game {
private:
    int round;
    Environment* environment;
    vector<AntHill *> antHills;
public:
    Game() {
        AntHill *antHill = new AntHill(10, 10, 1000, 1000);
        antHills.push_back(antHill);
    }
    void moveAllAnts();
    void createPheromons();
    void removeFoodFromEnv();




};


#endif //CPP_ANTSCOLONY_GAME_H
