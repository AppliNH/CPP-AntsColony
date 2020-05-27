#ifndef CPP_ANTSCOLONY_ANTHILL_H
#define CPP_ANTSCOLONY_ANTHILL_H


#include <ants/ant_queen/AntQueen.h>

class AntHill {

private:
    int posX;
    int posY;
    int maxPopulation;
    int maxFood;
    //vector<Ant> inhabitants;
    //vector<Food> foodStock;

public:
    bool operator==(const AntHill &);

};


#endif //CPP_ANTSCOLONY_ANTHILL_H
