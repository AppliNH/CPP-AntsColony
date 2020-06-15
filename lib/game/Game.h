//
// Created by Thomas Martin on 30/05/2020.
//

#ifndef CPP_ANTSCOLONY_GAME_H
#define CPP_ANTSCOLONY_GAME_H


#include "environment/Environment.h"
#include "ants/ant/Ant.h"
#include "ants/ant_worker/AntWorker.h"
#include "ants/ant_warrior/AntWarrior.h"
#include "ants/ant_queen/AntQueen.h"

#include <unistd.h>
#include <iostream>

class Game {
private:
    int round;
    Environment *environment;
    vector<AntHill *> antHills;
    vector<Ant *> ants;
    vector<LivingAnt *> livingAnts;
public:
    Game(int W, int H, int antHillX, int antHillY, int population, int foodCount, int obstacleCount);

    ~Game();

    void start();

    char analyzeEnv(LivingAnt &livingAnt);

    char getDirectionTo(LivingAnt &livingAnt, SquareBox &squareBow);

    void moveAllAnts();

    char dodgeObstacle(LivingAnt &livingAnt);

    void displayGrid();


};


#endif //CPP_ANTSCOLONY_GAME_H
