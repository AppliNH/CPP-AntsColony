//
// Created by Thomas Martin on 30/05/2020.
//

#include "Game.h"

Game::Game(int W, int H, int antHillX, int antHillY, int maxPopulation, int maxFood) : round(0)  {

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

char Game::analyzeEnv(vector<Food *> &food, const int &posX, const int &posY) {
    char newDirection = ' ';
    // Get the line above the ant. Empty vector if out of the grid
    vector<SquareBox *> above_line = posY + 1 < environment->getHeight() ? environment->getGrid().at(posY + 1) : vector<SquareBox *>();
    // Get the line where is the ant
    vector<SquareBox *> current_line = environment->getGrid().at(posY);
    // Get the line bellow the ant. Empty vector if out of the grid
    vector<SquareBox *> below_line = posY - 1 >= 0 ? environment->getGrid().at(posY - 1) : vector<SquareBox *>();

    // Check if on a food
    if (Food *f = dynamic_cast<Food *>(current_line.at(posX))) {
        food.push_back(new Food(environment->getGrid().at(posY).at(posX)->getPosX(), environment->getGrid().at(posY).at(posX)->getPosY()));
        // Delete the food
        environment->deleteSquareBox(posX, posY);
        cout << ">> I am on a food <<" << endl;
    }
    // Check if bellow a food
    if (!above_line.empty() && dynamic_cast<Food *>(above_line.at(posX))) {
        cout << ">> I am bellow a food (toward T) <<" << endl;
        newDirection = 'T';

    }
    // Check if above a food
    if (!below_line.empty() && dynamic_cast<Food *>(below_line.at(posX))) {
        cout << ">> I am above a food (toward B) <<" << endl;
        newDirection = 'B';

    }
    // Check if right of food
    if (posX - 1 >= 0 && dynamic_cast<Food *>(current_line.at(posX - 1))) {
        cout << ">> I am at the right of a food (toward L) <<" << endl;
        newDirection = 'L';
    }
    // Check if left of food
    if (posX + 1 < environment->getWidth() && dynamic_cast<Food *>(current_line.at(posX + 1))) {
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
    }
}

void Game::moveAllAnts() {
    for (auto & livingAnt : livingAnts) {
        livingAnt->speak();
        char foo [4] = { 'L', 'R', 'T', 'B' };
        auto v1 = rand() % 5;
        char newDirection = analyzeEnv(livingAnt->getCarriedFood(), livingAnt->getPosX(), livingAnt->getPosY());
        if (newDirection != ' ') {
            livingAnt->move(newDirection);
        } else {
            livingAnt->move(foo[v1]);
        }
    }
}
