#ifndef CPP_ANTSCOLONY_ANTYOUNGQUEEN_H
#define CPP_ANTSCOLONY_ANTYOUNGQUEEN_H


#include "ants/living_ant/LivingAnt.h"
#include "ant_hill/AntHill.h"

class AntYoungQueen : public LivingAnt {
protected:
    int buildAntHillPosX;
    int buildAntHillPosY;
public:
    AntYoungQueen(AntHill &antHill, Environment &environment, int buildAntHillPosX, int buildAntHillPosY): LivingAnt(antHill, environment, 4, 0.05, 4), buildAntHillPosX(buildAntHillPosX), buildAntHillPosY(buildAntHillPosY) {};

    int getBuildAntHillPosX() const {
        return buildAntHillPosX;
    }

    int getBuildAntHillPosY() const {
        return buildAntHillPosY;
    }

    bool hasArrived() {return getPosX() == buildAntHillPosX && getPosY() == buildAntHillPosY; }

    void speak() override;
    bool isRequiredToEat() override;
    void eatFood() override;

};


#endif //CPP_ANTSCOLONY_ANTYOUNGQUEEN_H
