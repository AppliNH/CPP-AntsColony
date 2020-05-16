#include <string>
#include <vector>
#include "Food.h"

using namespace std;

class Ant
{
private:
    int lifePoints;
    int lifeThreshold;
    int posX;
    int posY;
    int maxCarriedFood;
    vector<Food> carriedFood;

public:
    Ant(int , int , int );
    void displayAnt();
    bool collectFood(const Food);
    void eat(const Food );
    void move(string dimension);
    void dieSlowly();
    bool isRequiredToEat();
};
