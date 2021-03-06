//
// Created by alex on 11/2/15.
//

#ifndef GAMETEST_HERO_H
#define GAMETEST_HERO_H

#include "entity.h"

class Hero: public Entity {
private:
    unsigned int level;
public:
    Hero(std::string, int health, unsigned int level);
    Hero(std::string); //a shorter constructor with standard create values
    unsigned int getLevel();
    void Levelup();
};


#endif //GAMETEST_HERO_H
