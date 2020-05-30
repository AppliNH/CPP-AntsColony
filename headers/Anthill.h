#include <string>
#include <vector>
#include "../src/Ant/Ant.h"
#include "AntQueen.h"

using namespace std;

class Anthill
{
private:
    int posX;
    int posY;
    int popMax;
    int foodMax;
    vector<Food> stockFood;
    vector<Ant> popAnts;
    AntQueen antQueen;
public:
    Anthill(/* args */);
    ~Anthill();
};