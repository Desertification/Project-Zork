//
// Created by alex on 11/18/15.
//

#ifndef GAMETEST_MONSTER_H
#define GAMETEST_MONSTER_H


#include "entity.h"

class Monster: public Entity {
private:
    int aggressiveness;
    //-1:dead
    //1:ignores all combat
    //2:joins when another engaged in combat together (to be implemented)
    //3:attacks as soon you enter its territory

public:
    Monster(std::string name,int aggressiveness, int health, int stamina, int quickness, int armor, int damage);
    int getAggressiveness();
    void killed();
};


#endif //GAMETEST_MONSTER_H
