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
#include <unistd.h>

class Game {
private:
    int round;
    Environment *environment;
    vector<AntHill *> antHills;
    vector<Ant *> ants;
    vector<LivingAnt *> livingAnts;
public:
    Game(int W, int H, int antHillX, int antHillY, int maxPop, int maxFd) {

        environment = new Environment(W, H);

        AntHill *antHill = new AntHill(antHillX, antHillY, maxPop, maxFd);
        antHills.push_back(antHill);

        AntQueen *antQueen = new AntQueen(*antHill, *environment);
        livingAnts.push_back(antQueen);

        for (int i = 0; i < int(maxPop / 4); ++i) {
            LivingAnt *antWorker = new AntWorker(*antHill, *environment);
            livingAnts.push_back(antWorker);
        }
        for (int i = 0; i < int(maxPop / 4); ++i) {
            LivingAnt *antWarrior = new AntWarrior(*antHill, *environment);
            livingAnts.push_back(antWarrior);
        }

    }

    void start() {
        while (true) {
            round++;
            moveAllAnts();
            cout << "Game started, round : " << round << endl;
            usleep(1000000);
        }
    }

    void mockFood() {

    }


    void moveAllAnts() {
        for (int i = 0; i < livingAnts.size(); ++i) {
            char foo [4] = { 'L', 'R', 'T', 'B' };
            auto v1 = rand() % 5;
            livingAnts[i]->move(foo[v1]);
        }
    };

    void createPheromons();

    void removeFoodFromEnv();


};


#endif //CPP_ANTSCOLONY_GAME_H
