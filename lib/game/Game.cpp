//
// Created by Thomas Martin on 30/05/2020.
//

#include "Game.h"

Game::Game(int W, int H, int antHillX, int antHillY, int population, int foodCount, int obstacleCount) : round(0) {


    AntHill *antHill = new AntHill(antHillX, antHillY, population, foodCount);
    environment = new Environment(H, W, foodCount, obstacleCount, antHill);

    antHills.push_back(antHill);

    AntQueen *antQueen = new AntQueen(*antHill, *environment);
    livingAnts.push_back(antQueen);

    for (int i = 0; i < int(population) / 2; ++i) {
        LivingAnt *antWorker = new AntWorker(*antHill, *environment);
        livingAnts.push_back(antWorker);
    }
    for (int i = 0; i < int(population) / 2; ++i) {
        LivingAnt *antWarrior = new AntWarrior(*antHill, *environment);
        livingAnts.push_back(antWarrior);
    }

}


char Game::analyzeEnv(LivingAnt &livingAnt) {

    vector<char> choiceLevel1;
    vector<char> choiceLevel2;

    if (livingAnt.isFullOfFood()) return getDirectionTo(livingAnt, livingAnt.getAntHill());
    // Get the first line above the ant. Empty vector if out of the grid
    vector<SquareBox *> belowLine1 =
            livingAnt.getPosY() + 1 < environment->getHeight() ? environment->getGrid().at(livingAnt.getPosY() + 1)
                                                               : vector<SquareBox *>();
    // Get the second above the ant. Empty vector if out of the grid
    vector<SquareBox *> belowLine2 =
            livingAnt.getPosY() + 2 < environment->getHeight() ? environment->getGrid().at(livingAnt.getPosY() + 2)
                                                               : vector<SquareBox *>();
    // Get the line where is the ant
    vector<SquareBox *> currentLine = environment->getGrid().at(livingAnt.getPosY());
    // Get the first line bellow the ant. Empty vector if out of the grid
    vector<SquareBox *> aboveLine1 =
            livingAnt.getPosY() - 1 >= 0 ? environment->getGrid().at(livingAnt.getPosY() - 1) : vector<SquareBox *>();
    // Get the second line bellow the ant. Empty vector if out of the grid
    vector<SquareBox *> aboveLine2 =
            livingAnt.getPosY() - 2 >= 0 ? environment->getGrid().at(livingAnt.getPosY() - 2) : vector<SquareBox *>();

    // Check if on a food
    if (Food *f = dynamic_cast<Food *>(currentLine.at(livingAnt.getPosX()))) {
        if (livingAnt.grabFood(*f)) {
            f->grabFood();
            if (f->getSize() == 0) {
                // Delete the food
                environment->deleteSquareBox(livingAnt.getPosX(), livingAnt.getPosY());
            }
            cout << "   >> I grabbed a food <<" << endl;
            return ' ';
        } else {
            cout << "   >> I'm full <<" << endl;
        }
    }
    // Check if directly bellow a food
    if (!belowLine1.empty() && dynamic_cast<Food *>(belowLine1.at(livingAnt.getPosX()))) {
        cout << "   >> Food towards Top (+1) <<" << endl;
        choiceLevel1.push_back('T');

    }
    // Check if bellow a food
    if (!belowLine2.empty() && dynamic_cast<Food *>(belowLine2.at(livingAnt.getPosX()))) {
        cout << "   >> Food towards Top (+2) <<" << endl;
        choiceLevel2.push_back('T');

    }
    // Check if directly above a food
    if (!aboveLine1.empty() && dynamic_cast<Food *>(aboveLine1.at(livingAnt.getPosX()))) {
        cout << "   >> Food towards Bottom (+1) <<" << endl;
        choiceLevel1.push_back('B');

    }
    // Check if above a food
    if (!aboveLine2.empty() && dynamic_cast<Food *>(aboveLine2.at(livingAnt.getPosX()))) {
        cout << "   >> Food towards Bottom (+2) <<" << endl;
        choiceLevel2.push_back('B');

    }
    // Check if directly right of food
    if (livingAnt.getPosX() - 1 >= 0 && dynamic_cast<Food *>(currentLine.at(livingAnt.getPosX() - 1))) {
        cout << "   >> Food towards Left (+1) <<" << endl;
        choiceLevel1.push_back('L');
    }
    // Check if right of food
    if (livingAnt.getPosX() - 2 >= 0 && dynamic_cast<Food *>(currentLine.at(livingAnt.getPosX() - 2))) {
        cout << "   >> Food towards Left (+2) <<" << endl;
        choiceLevel2.push_back('L');
    }
    // Check if left of food
    if (livingAnt.getPosX() + 1 < environment->getWidth() &&
        dynamic_cast<Food *>(currentLine.at(livingAnt.getPosX() + 1))) {
        cout << "   >> Food towards Right (+1) <<" << endl;
        choiceLevel1.push_back('R');
    }
    // Check if left of food
    if (livingAnt.getPosX() + 2 < environment->getWidth() &&
        dynamic_cast<Food *>(currentLine.at(livingAnt.getPosX() + 2))) {
        cout << "   >> Food towards Right (+2) <<" << endl;
        choiceLevel2.push_back('R');
    }

    if (!choiceLevel1.empty()) {
        return choiceLevel1.at(rand() % choiceLevel1.size());
    } else if (!choiceLevel2.empty()) {
        return choiceLevel2.at(rand() % choiceLevel2.size());
    } else {
        return dodgeObstacle(livingAnt);
    }
}

void Game::start() {
    while (true) {
        system("clear");
        environment->pheromoneDecay();
        environment->status();
        displayGrid();
        for (auto &antHill : antHills) {
            antHill->status();
        }
        cout << "#########" << endl;
        cout << "Round : " << round << endl;
        if (!livingAnts.empty()) {
            moveAllAnts();
        } else {
            cout << "GAME ENDED" << endl;
            break;
        }
        round++;
        usleep(1000000);
        cout << endl;
    }

}


void Game::moveAllAnts() {
    for (int i = 0; i < livingAnts.size(); ++i) {
        if (livingAnts.at(i)->dieSlowly(round)) {
            livingAnts.erase(livingAnts.begin() + i);
            return;
        }
        livingAnts.at(i)->speak();
        if (livingAnts.at(i)->isFullOfFood() && livingAnts.at(i)->isAtHome()) {
            livingAnts.at(i)->layDownFoodInAntHill();
        }
        char newDirection = analyzeEnv(*livingAnts.at(i));
        livingAnts.at(i)->move(newDirection);

    }
}

char Game::getDirectionTo(LivingAnt &livingAnt, SquareBox &squareBow) {
    char newDirection = ' ';
    // Get the line where is the ant
    vector<SquareBox *> current_line = environment->getGrid().at(livingAnt.getPosY());

    if (livingAnt.getPosX() - 1 >= 0 && squareBow.getPosX() < livingAnt.getPosX()) {
        newDirection = 'L';
    }

    if (livingAnt.getPosX() + 1 < environment->getWidth() && squareBow.getPosX() > livingAnt.getPosX()) {
        newDirection = 'R';
    }

    if (livingAnt.getPosY() - 1 >= 0 && squareBow.getPosY() < livingAnt.getPosY()) {
        newDirection = 'T';
    }

    if (livingAnt.getPosY() + 1 < environment->getHeight() && squareBow.getPosY() > livingAnt.getPosY()) {
        newDirection = 'B';
    }

    return newDirection;
}

Game::~Game() {
    for (auto l : livingAnts) {
        delete l;
    }
    for (auto a : ants) {
        delete a;
    }
    for (auto ah : antHills) {
        delete ah;
    }
    delete environment;
    livingAnts.clear();
    antHills.clear();
    ants.clear();
}

char Game::dodgeObstacle(LivingAnt &livingAnt) {
    vector<char> choice;

    // Check if directly bellow a food
    vector<SquareBox *> belowLine1 =
            livingAnt.getPosY() + 1 < environment->getHeight() ? environment->getGrid().at(livingAnt.getPosY() + 1)
                                                               : vector<SquareBox *>();
    // Get the line where is the ant
    vector<SquareBox *> currentLine = environment->getGrid().at(livingAnt.getPosY());
    // Get the first line bellow the ant. Empty vector if out of the grid
    vector<SquareBox *> aboveLine1 =
            livingAnt.getPosY() - 1 >= 0 ? environment->getGrid().at(livingAnt.getPosY() - 1) : vector<SquareBox *>();

    if (livingAnt.getPosX() - 1 >= 0 && !dynamic_cast<Obstacle *>(currentLine.at(livingAnt.getPosX() - 1))) {
        choice.push_back('L');
    }
    if (livingAnt.getPosX() + 1 < environment->getWidth() &&
        !dynamic_cast<Obstacle *>(currentLine.at(livingAnt.getPosX() + 1))) {
        choice.push_back('R');
    }
    if (!aboveLine1.empty() && !dynamic_cast<Obstacle *>(aboveLine1.at(livingAnt.getPosX()))) {
        choice.push_back('T');
    }
    if (!belowLine1.empty() && !dynamic_cast<Obstacle *>(belowLine1.at(livingAnt.getPosX()))) {
        choice.push_back('B');
    }
    return choice.at(rand() % choice.size());

}

void Game::displayGrid() {
    for (int row = 0; row < environment->getHeight(); ++row) {
        for (int column = 0; column < environment->getHeight(); ++column) {
            if (dynamic_cast<Pheromone *>(environment->getGrid().at(row).at(column))) {
                cout << "|\U0001F300";
            } else if (dynamic_cast<Food *>(environment->getGrid().at(row).at(column))) {
                cout << "|\U0001F370";
            } else if (dynamic_cast<Obstacle *>(environment->getGrid().at(row).at(column))) {
                cout << "|\U0001F4E6";
            } else if (dynamic_cast<LivingAnt *>(environment->getGrid().at(row).at(column))) {
                cout << "|\U0001F41C";
            } else if (dynamic_cast<AntHill *>(environment->getGrid().at(row).at(column))) {
                cout << "|\U0001F5FB";
            } else {
                cout << "|__";
            }
        }
        cout << "|" << endl;
    }
}

