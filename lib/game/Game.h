//
// Created by Thomas Martin on 30/05/2020.
//

#ifndef CPP_ANTSCOLONY_GAME_H
#define CPP_ANTSCOLONY_GAME_H


#include <environment/Environment.h>
#include <ants/ant/Ant.h>
#include <ants/ant_worker/AntWorker.h>
#include <ants/ant_warrior/AntWarrior.h>
#include <ants/ant_queen/AntQueen.h>

class Game {
private:
    int round;
    Environment* environment;
    vector<AntHill *> antHills;
    vector<Ant *> ants;
public:
    Game(int X, int Y, int maxPop, int maxFd) {

        environment = new Environment(100,100);

        AntHill *antHill = new AntHill(X, Y, maxPop, maxFd);
        antHills.push_back(antHill);

        AntQueen *antQueen = new AntQueen(*antHill, *environment);
        ants.push_back(antQueen);

        for (int i = 0; i < 250 ; ++i) {
            Ant *antWorker = new AntWorker(*antHill, *environment);
            ants.push_back(antWorker);
        }
        for (int i = 0; i < 250 ; ++i) {
            Ant *antWarrior = new AntWarrior(*antHill, *environment);
            ants.push_back(antWarrior);
        }

    }
    void moveAllAnts();
    void createPheromons();
    void removeFoodFromEnv();




};


#endif //CPP_ANTSCOLONY_GAME_H
