#ifndef CPP_ANTSCOLONY_ANTHILL_H
#define CPP_ANTSCOLONY_ANTHILL_H


#include <ants/ant_queen/AntQueen.h>

class AntHill: public SquareBox {

private:
    int maxPopulation;
    int maxFood;
    vector<Ant *> inhabitants;
    vector<Food *> foodStock;

public:
    AntHill(int X, int Y, int maxPop, int maxFd) : SquareBox(X, Y), maxPopulation(maxPop), maxFood(maxFd) {
        AntQueen *queen = new AntQueen();
        inhabitants.push_back(queen);
    }
    bool operator==(const AntHill &);

};


#endif //CPP_ANTSCOLONY_ANTHILL_H
