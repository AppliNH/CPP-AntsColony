#ifndef CPP_ANTSCOLONY_ANTYOUNGQUEEN_H
#define CPP_ANTSCOLONY_ANTYOUNGQUEEN_H


#include "ants/living_ant/LivingAnt.h"
#include "ants/ant_queen/AntQueen.h"
#include "ant_hill/AntHill.h"

class AntYoungQueen : public LivingAnt {
protected:
    int buildAntHillPosX;
    int buildAntHillPosY;
public:
    AntYoungQueen(AntHill &antHill, Environment &environment, const int &buildAntHillPosX, const int &buildAntHillPosY)
            : LivingAnt(
            antHill, environment, 4, 0.05, 4, 0, true), buildAntHillPosX(buildAntHillPosX), buildAntHillPosY(
            buildAntHillPosY) {};

    [[nodiscard]] int getBuildAntHillPosX() const {
        return buildAntHillPosX;
    }

    [[nodiscard]] int getBuildAntHillPosY() const {
        return buildAntHillPosY;
    }

    bool hasArrived();

    void speak() override;

    bool isRequiredToEat() override;

    void eatFood() override;

    LivingAnt *evolve() override;

};


#endif //CPP_ANTSCOLONY_ANTYOUNGQUEEN_H
