#ifndef CPP_ANTSCOLONY_ENVIRONMENT_H
#define CPP_ANTSCOLONY_ENVIRONMENT_H


#include "ant_hill/AntHill.h"
#include "pheromone/Pheromone.h"
#include "obstacle/Obstacle.h"

class Environment {
private:
    int width;
    int height;
    AntHill *antHill;
    vector<Food *> foods;
    vector<Pheromone *> pheromones;
    vector<Obstacle *> obstacles;
public:
    bool isCrossable(const int &posX, const int &posY);
};


#endif //CPP_ANTSCOLONY_ENVIRONMENT_H
