#ifndef CPP_ANTSCOLONY_ENVIRONMENT_H
#define CPP_ANTSCOLONY_ENVIRONMENT_H


#include "ant_hill/AntHill.h"
#include "pheromone/Pheromone.h"
#include "obstacle/Obstacle.h"
#include <iostream>
#include <memory>

using namespace std;

class Environment {
private:
    int width;
    int height;

    vector<vector<SquareBox *>> grid;

    vector<Food *> foods;
    vector<Pheromone *> pheromones;
    vector<Obstacle *> obstacles;
public:
    Environment(int h, int w);

    ~Environment();

    char analyzeEnv(const int &posX, const int &posY);

    void deleteSquareBox(const int &posX, const int &posY);

    void status();

    int & getWidth() { return width; }

    int & getHeight() { return height; }

    vector<vector<SquareBox *>> getGrid() { return grid; }
};


#endif //CPP_ANTSCOLONY_ENVIRONMENT_H
