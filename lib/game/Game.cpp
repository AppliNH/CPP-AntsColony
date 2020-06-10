//
// Created by Thomas Martin on 30/05/2020.
//

#include "Game.h"

Game::Game(int W, int H, int antHillX, int antHillY, int maxPopulation, int maxFood) : round(0) {

    environment = new Environment(H, W);

    AntHill *antHill = new AntHill(antHillX, antHillY, maxPopulation, maxFood);
    antHills.push_back(antHill);

    AntQueen *antQueen = new AntQueen(*antHill, *environment);
    livingAnts.push_back(antQueen);

    for (int i = 0; i < int(maxPopulation); ++i) {
        LivingAnt *antWorker = new AntWorker(*antHill, *environment);
        livingAnts.push_back(antWorker);
    }
    for (int i = 0; i < int(maxPopulation); ++i) {
        LivingAnt *antWarrior = new AntWarrior(*antHill, *environment);
        livingAnts.push_back(antWarrior);
    }

}


char Game::analyzeEnv(LivingAnt &livingAnt) {
    if (livingAnt.isFullOfFood()) return getDirectionToTheAntHill(livingAnt);
    char newDirection = ' ';
    // Get the line above the ant. Empty vector if out of the grid
    vector<SquareBox *> above_line =
            livingAnt.getPosY() + 1 < environment->getHeight() ? environment->getGrid().at(livingAnt.getPosY() + 1)
                                                               : vector<SquareBox *>();
    // Get the line where is the ant
    vector<SquareBox *> current_line = environment->getGrid().at(livingAnt.getPosY());
    // Get the line bellow the ant. Empty vector if out of the grid
    vector<SquareBox *> below_line =
            livingAnt.getPosY() - 1 >= 0 ? environment->getGrid().at(livingAnt.getPosY() - 1) : vector<SquareBox *>();

    // Check if on a food
    if (Food *f = dynamic_cast<Food *>(current_line.at(livingAnt.getPosX()))) {
        if (livingAnt.collectFood(*f)) {
            // Delete the food
            environment->deleteSquareBox(livingAnt.getPosX(), livingAnt.getPosY());
            cout << ">> I grabbed a food <<" << endl;
        } else {
            cout << ">> I'm full <<" << endl;
        }
    }
    // Check if bellow a food
    if (!above_line.empty() && dynamic_cast<Food *>(above_line.at(livingAnt.getPosX()))) {
        cout << ">> I am bellow a food (toward T) <<" << endl;
        newDirection = 'T';

    }
    // Check if above a food
    if (!below_line.empty() && dynamic_cast<Food *>(below_line.at(livingAnt.getPosX()))) {
        cout << ">> I am above a food (toward B) <<" << endl;
        newDirection = 'B';

    }
    // Check if right of food
    if (livingAnt.getPosX() - 1 >= 0 && dynamic_cast<Food *>(current_line.at(livingAnt.getPosX() - 1))) {
        cout << ">> I am at the right of a food (toward L) <<" << endl;
        newDirection = 'L';
    }
    // Check if left of food
    if (livingAnt.getPosX() + 1 < environment->getWidth() &&
        dynamic_cast<Food *>(current_line.at(livingAnt.getPosX() + 1))) {
        cout << ">> I am at the left of a food (toward R) <<" << endl;
        newDirection = 'R';
    }

    return newDirection;
}

void Game::start() {
    while (true) {
        cout << "Game started, round : " << round << endl;
        moveAllAnts();
        round++;
        usleep(1000000);
        cout << endl;
        environment->status();
        for (auto &antHill : antHills) {
            antHill->status();
        }
        cout << "#########" << endl;

    }
}

void Game::moveAllAnts() {
    for (auto &livingAnt : livingAnts) {
        livingAnt->speak();
        char foo[4] = {'L', 'R', 'T', 'B'};
        auto v1 = rand() % 5;
        if (livingAnt->isFullOfFood() && livingAnt->isAtHome()) {
            livingAnt->layDownFoodInAntHill();
        }
        char newDirection = analyzeEnv(*livingAnt);
        if (newDirection != ' ') {
            livingAnt->move(newDirection);
        } else {
            livingAnt->move(foo[v1]);
        }

    }
}

char Game::getDirectionToTheAntHill(LivingAnt &livingAnt) {
    char newDirection = ' ';
    // Get the line where is the ant
    vector<SquareBox *> current_line = environment->getGrid().at(livingAnt.getPosY());

    if (livingAnt.getPosX() - 1 >= 0 && livingAnt.getAntHill().getPosX() < livingAnt.getPosX()) {
        newDirection = 'L';
    }

    if (livingAnt.getPosX() + 1 < environment->getWidth() && livingAnt.getAntHill().getPosX() > livingAnt.getPosX()) {
        newDirection = 'R';
    }

    if (livingAnt.getPosY() - 1 >= 0 && livingAnt.getAntHill().getPosY() < livingAnt.getPosY()) {
        newDirection = 'B';
    }

    if (livingAnt.getPosY() + 1 < environment->getHeight() && livingAnt.getAntHill().getPosY() > livingAnt.getPosY()) {
        newDirection = 'T';
    }

    return newDirection;
}
