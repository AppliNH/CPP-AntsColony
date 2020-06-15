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

    vector<Food> foods;
    vector<Pheromone> pheromones;
    vector<AntHill *> antHills;
    vector<Obstacle> obstacles;
public:
    Environment(int h, int w, int foodCount, int obstacleCount, AntHill *antHill);

    ~Environment();

    char analyzeEnv(const int &posX, const int &posY);

    void deleteSquareBox(const int &posX, const int &posY);

    vector<AntHill *> getAntHills();

    void status();

    int & getWidth() { return width; }

    int & getHeight() { return height; }

    SquareBox * getSquareBoxAt(const int &posX, const int &posY);

    vector<vector<SquareBox *>> getGrid() { return grid; }

    void insertPheromone(const int &posX, const int &posY);

    void pheromoneDecay();
};


#endif //CPP_ANTSCOLONY_ENVIRONMENT_H
