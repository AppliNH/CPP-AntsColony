#ifndef CPP_ANTSCOLONY_ENVIRONMENT_H
#define CPP_ANTSCOLONY_ENVIRONMENT_H


#include "ant_hill/AntHill.h"
#include "pheromone/Pheromone.h"
#include "obstacle/Obstacle.h"
using namespace std;
class Environment {
private:
    int width;
    int height;

    vector<Food *> foods;
    vector<Pheromone *> pheromones;
    vector<Obstacle *> obstacles;
public:
    Environment(int h, int w) : height(h), width(w) {

        Food *food = new Food(10,10);
        foods.push_back(food);

        Pheromone *pheromone = new Pheromone(20,20,5);
        pheromones.push_back(pheromone);

        Obstacle *obstacle = new Obstacle(10,10);
        obstacles.push_back(obstacle);
    }
    bool isCrossable(const int &posX, const int &posY);

    vector<SquareBox> analyzeEnv(const int &posX, const int &posY);

    int getWidth() { return width;}
    int getHeight() { return height;}
};


#endif //CPP_ANTSCOLONY_ENVIRONMENT_H
