#ifndef CPP_ANTSCOLONY_ENVIRONMENT_H
#define CPP_ANTSCOLONY_ENVIRONMENT_H


#include "ant_hill/AntHill.h"
#include "pheromone/Pheromone.h"
#include "obstacle/Obstacle.h"

#include <iostream>
#include <memory>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

using namespace std;

class Environment {
private:
    int width;
    int height;
    vector<vector<SquareBox *>> grid;
    vector<Pheromone> pheromones;
    vector<AntHill *> antHills;

    void buildGrid(const int &w, const int &h);

    void insertObstacles(const int &obstacleCount);

public:
    Environment(const int &height, const int &width, const int &foodCount, const int &obstacleCount, AntHill *antHill);

    ~Environment();

    void deleteSquareBox(const int &posX, const int &posY);

    void insertFoods(const int &foodCount);

    vector<AntHill *> getAntHills();

    void addAntHill(AntHill *antHill);

    void status();

    [[nodiscard]] int getWidth() const { return width; }

    [[nodiscard]] int getHeight() const { return height; }

    vector<vector<SquareBox *>> getGrid() { return grid; }

    void insertPheromone(const int &posX, const int &posY);

    void pheromoneDecay();

    void getEmptySquareBox(int &posX, int &posY);
};


#endif //CPP_ANTSCOLONY_ENVIRONMENT_H
