//
// Created by Thomas Martin on 30/05/2020.
//

#include "Game.h"

Game::Game(int population, int W, int H, int foodCount, int obstacleCount) : round(0) {

    AntHill *antHill = new AntHill(W / 2, H / 2);
    environment = new Environment(H, W, foodCount, obstacleCount, antHill);

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

    displayGrid();

}

template<typename T>
void Game::resourcesSearch(LivingAnt &livingAnt, vector<char> &choiceList, int level) {
    vector<SquareBox *> belowLine = livingAnt.getPosY() + level < environment->getHeight() ? environment->getGrid().at(
            livingAnt.getPosY() + level)
                                                                                           : vector<SquareBox *>();
    vector<SquareBox *> aboveLine =
            livingAnt.getPosY() - level >= 0 ? environment->getGrid().at(livingAnt.getPosY() - level)
                                             : vector<SquareBox *>();
    vector<SquareBox *> currentLine = environment->getGrid().at(livingAnt.getPosY());

    // Check if bellow a food
    if (!belowLine.empty() && dynamic_cast<T *>(belowLine.at(livingAnt.getPosX()))) {
        //cout << "   >> Food towards Bottom (+" + to_string(level) + ") <<" << endl;
        choiceList.push_back('B');
    }

    // Check if above a food
    if (!aboveLine.empty() && dynamic_cast<T *>(aboveLine.at(livingAnt.getPosX()))) {
        //cout << "   >> Food towards Top (+" + to_string(level) + ") <<" << endl;
        choiceList.push_back('T');
    }

    // Check if left of food
    if (livingAnt.getPosX() - level >= 0 && dynamic_cast<T *>(currentLine.at(livingAnt.getPosX() - level))) {
        //cout << "   >> Food towards Left (+" + to_string(level) + ") <<" << endl;
        choiceList.push_back('L');
    }

    // Check if right of food
    if (livingAnt.getPosX() + level < environment->getWidth() &&
        dynamic_cast<T *>(currentLine.at(livingAnt.getPosX() + level))) {
        //cout << "   >> Food towards Right (+" + to_string(level) + ") <<" << endl;
        choiceList.push_back('R');
    }

}


char Game::analyzeEnv(LivingAnt &livingAnt) {

    vector<char> choiceLevel1;
    vector<char> choiceLevel2;

    choiceLevel1.push_back(dodgeObstacle(livingAnt));
    choiceLevel2.push_back(dodgeObstacle(livingAnt));

    int initialChoiceSize1 = choiceLevel1.size();
    int initialChoiceSize2 = choiceLevel2.size();

    if (livingAnt.isFullOfFood()) return getDirectionTo(livingAnt, livingAnt.getAntHill());

    // Get the line where the ant is
    vector<SquareBox *> currentLine = environment->getGrid().at(livingAnt.getPosY());

    // Check if on a food
    if (Food *f = dynamic_cast<Food *>(currentLine.at(livingAnt.getPosX()))) {
        if (livingAnt.grabFood(*f)) {
            f->grabFood();
            if (f->getSize() == 0) {
                // Delete the food
                environment->deleteSquareBox(livingAnt.getPosX(), livingAnt.getPosY());
                environment->insertFoods(1);
            }
            cout << "   >> I grabbed a food <<" << endl;
            return ' ';
        } else {
            cout << "   >> I'm full <<" << endl;
        }
    }
    resourcesSearch<Food>(livingAnt, choiceLevel1, 1);
    resourcesSearch<Food>(livingAnt, choiceLevel2, 2);

    // Pheromons decisions
    if (choiceLevel1.size() == initialChoiceSize1) {
        resourcesSearch<Pheromone>(livingAnt, choiceLevel1, 1);
    }

    if (choiceLevel2.size() == initialChoiceSize2) {
        resourcesSearch<Pheromone>(livingAnt, choiceLevel2, 2);
    }

    if (!choiceLevel1.empty()) {
        dodgeObstacle2(livingAnt, choiceLevel1);
        return choiceLevel1.at(rand() % choiceLevel1.size());
    } else if (!choiceLevel2.empty()) {
        dodgeObstacle2(livingAnt, choiceLevel2);
        return choiceLevel2.at(rand() % choiceLevel2.size());
    } else {
        return dodgeObstacle(livingAnt);
    }
}

void Game::start() {
    while (true) {
        if (round == 30) {
            getPositionForFutureAntHill();
        }
        system("clear");
        environment->pheromoneDecay();
        environment->status();
        displayGrid();
        for (auto &antHill : environment->getAntHills()) {
            antHill->status();
            cout << "Population : " << getPopulationPerAntHill(*antHill) << endl;
            cout << "Eggs : " << getEggsPerAntHill(*antHill) << endl;
            growEggs(*antHill);
        }
        cout << "#########" << endl;
        cout << "Round : " << round << endl;
        if (!livingAnts.empty()) {
            manageAllAnts();
        } else {
            cout << "GAME ENDED" << endl;
            return;
        }
        round++;
        usleep(100000);
        cout << endl;
    }

}


void Game::manageAllAnts() {
    for (int i = 0; i < livingAnts.size(); ++i) {
        livingAnts.at(i)->
        if (livingAnts.at(i)->looseLife()) {
            livingAnts.erase(livingAnts.begin() + i);
            return;
        }

        //livingAnts.at(i)->speak();
        if (AntQueen *antQueen = dynamic_cast<AntQueen *>(livingAnts.at(i))) {
            layEgg(antQueen);
        }
        if (AntYoungQueen *antYoungQueen = dynamic_cast<AntYoungQueen *>(livingAnts.at(i))) {
            if (antYoungQueen->hasArrived()) {
                auto newAntHill = new AntHill(antYoungQueen->getPosX(), antYoungQueen->getPosY());
                environment->addAntHill(newAntHill);
                livingAnts.push_back(new AntQueen(*newAntHill, *environment));
                livingAnts.erase(livingAnts.begin() + i);
                return;
            } else {
                SquareBox box(antYoungQueen->getBuildAntHillPosX(), antYoungQueen->getBuildAntHillPosY());
                livingAnts.at(i)->move(getDirectionTo(*livingAnts.at(i), box));
                return;
            }
        }
        if (livingAnts.at(i)->isFullOfFood() && livingAnts.at(i)->isAtHome()) {
            livingAnts.at(i)->layDownFoodInAntHill();
        }
        char newDirection = analyzeEnv(*livingAnts.at(i));
        if (livingAnts.at(i)->isRequiredToEat()) livingAnts.at(i)->eatFood();
        livingAnts.at(i)->move(newDirection);

    }
}

char Game::getDirectionTo(LivingAnt &livingAnt, SquareBox &squareBox) {
    vector<char> possibleDir;

    // Get the line where is the ant
    vector<SquareBox *> current_line = environment->getGrid().at(livingAnt.getPosY());

    if (livingAnt.getPosX() - 1 >= 0 && squareBox.getPosX() < livingAnt.getPosX()) {
        possibleDir.push_back('L');
    }

    if (livingAnt.getPosX() + 1 < environment->getWidth() && squareBox.getPosX() > livingAnt.getPosX()) {
        possibleDir.push_back('R');
    }

    if (livingAnt.getPosY() - 1 >= 0 && squareBox.getPosY() < livingAnt.getPosY()) {
        possibleDir.push_back('T');
    }

    if (livingAnt.getPosY() + 1 < environment->getHeight() && squareBox.getPosY() > livingAnt.getPosY()) {
        possibleDir.push_back('B');
    }
    dodgeObstacle2(livingAnt, possibleDir);
    return possibleDir.at(rand() % possibleDir.size());
}

Game::~Game() {
    for (auto &l : livingAnts) {
        delete l;
    }
    for (auto &a : ants) {
        delete a;
    }
    delete environment;
    livingAnts.clear();
    ants.clear();
}

void Game::dodgeObstacle2(LivingAnt &livingAnt, vector<char> &choiceList) {


    // Check if directly bellow a food
    vector<SquareBox *> belowLine1 =
            livingAnt.getPosY() + 1 < environment->getHeight() ? environment->getGrid().at(livingAnt.getPosY() + 1)
                                                               : vector<SquareBox *>();
    // Get the line where is the ant
    vector<SquareBox *> currentLine = environment->getGrid().at(livingAnt.getPosY());
    // Get the first line bellow the ant. Empty vector if out of the grid
    vector<SquareBox *> aboveLine1 =
            livingAnt.getPosY() - 1 >= 0 ? environment->getGrid().at(livingAnt.getPosY() - 1) : vector<SquareBox *>();


    if (livingAnt.getPosX() - 1 < 0) {
        choiceList.erase(std::remove(choiceList.begin(), choiceList.end(), 'L'), choiceList.end());
    } else if (dynamic_cast<Obstacle *>(currentLine.at(livingAnt.getPosX() - 1))) {
        choiceList.erase(std::remove(choiceList.begin(), choiceList.end(), 'L'), choiceList.end());
    }

    if (livingAnt.getPosX() + 1 >= environment->getWidth()) {
        choiceList.erase(std::remove(choiceList.begin(), choiceList.end(), 'R'), choiceList.end());
    } else if (dynamic_cast<Obstacle *>(currentLine.at(livingAnt.getPosX() + 1))) {
        choiceList.erase(std::remove(choiceList.begin(), choiceList.end(), 'R'), choiceList.end());
    }

    if (aboveLine1.empty() || dynamic_cast<Obstacle *>(aboveLine1.at(livingAnt.getPosX()))) {
        choiceList.erase(std::remove(choiceList.begin(), choiceList.end(), 'T'), choiceList.end());
    }
    if (belowLine1.empty() || dynamic_cast<Obstacle *>(belowLine1.at(livingAnt.getPosX()))) {
        choiceList.erase(std::remove(choiceList.begin(), choiceList.end(), 'B'), choiceList.end());
    }

    if (choiceList.size() == 0) {
        choiceList.push_back(dodgeObstacle(livingAnt));
    }

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
        for (int column = 0; column < environment->getWidth(); ++column) {
            string icon;
            if (find_if(livingAnts.begin(), livingAnts.end(),
                        [row, column](LivingAnt *m) -> bool {
                            return dynamic_cast<AntYoungQueen *>(m) && m->getPosY() == row && m->getPosX() == column;
                        }) != livingAnts.end()) {
                icon = "|\U0001F451";
            } else if (dynamic_cast<Food *>(environment->getGrid().at(row).at(column))) {
                icon = "|\U0001F370";
            } else if (dynamic_cast<Obstacle *>(environment->getGrid().at(row).at(column))) {
                icon = "|\U0001F4E6";
            } else if (dynamic_cast<AntHill *>(environment->getGrid().at(row).at(column))) {
                icon = "|\U0001F5FB";
            } else if (find_if(livingAnts.begin(), livingAnts.end(),
                               [row, column](LivingAnt *m) -> bool {
                                   return m->getPosY() == row && m->getPosX() == column;
                               }) != livingAnts.end()) {
                icon = "|\U0001F41C";
            } else if (dynamic_cast<Pheromone *>(environment->getGrid().at(row).at(column))) {
                icon = "|\U0001F300";
            } else {
                icon = "|__";
            }
            cout << icon;
        }
        cout << "|" << endl;
    }
}

void Game::layEgg(AntQueen *antQueen) {
    if (antQueen->getAntHill().getMaxPopulation() > getPopulationPerAntHill(antQueen->getAntHill())) {
        std::knuth_b rand_engine;
        double p = 0.02;
        if (antQueen->getAntHill().getMaxPopulation() - getPopulationPerAntHill(antQueen->getAntHill()) <= 10) {
            p = 0.1;
        }
        std::bernoulli_distribution d(p);
        bool decision = d(rand_engine);
        eggs.push_back(new AntEgg(antQueen->getAntHill(), decision));
    }
}

int Game::getPopulationPerAntHill(const AntHill &antHill) {
    int pop = 0;
    for (int i = 0; i < livingAnts.size(); ++i) {
        if (livingAnts.at(i)->getAntHill() == antHill) {
            pop++;
        }
    }
    return pop + getEggsPerAntHill(antHill);
}

int Game::getEggsPerAntHill(const AntHill &antHill) {
    int eggCount = 0;
    for (int i = 0; i < eggs.size(); ++i) {
        if (eggs.at(i)->getAntHill() == antHill) {
            eggCount++;
        }
    }
    return eggCount;
}

void Game::growEggs(AntHill &antHill) {
    for (int i = 0; i < eggs.size(); ++i) {
        if (eggs.at(i)->grow()) {
            eggs.erase(eggs.begin());
            livingAnts.push_back(new AntWorker(antHill, *environment));
        }
    }
}

void Game::getPositionForFutureAntHill() {
    int antHillPosX;
    int antHillPosY;
    environment->getEmptySquareBox(antHillPosX, antHillPosY);
    livingAnts.push_back(new AntYoungQueen(*environment->getAntHills().at(0), *environment, antHillPosX, antHillPosY));
}

