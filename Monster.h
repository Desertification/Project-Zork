//
// Created by alex on 11/18/15.
//

#ifndef GAMETEST_MONSTER_H
#define GAMETEST_MONSTER_H


#include "entity.h"

class Monster: public Entity {
private:
    int aggressiveness;
    //1:ignores all combat
    //2:joins when another engaged in combat together
    //3:attacks as soon you enter its territory

    unsigned int id;
public:
    Monster(std::string, unsigned int id,int aggressiveness, int health, int stamina, int quickness, int armor, int damage);
    int getAggressiveness();
    unsigned int getId();
};


#endif //GAMETEST_MONSTER_H
