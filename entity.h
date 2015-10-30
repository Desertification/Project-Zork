//
// Created by thoma on 9/10/2015.
//

#ifndef GAMETEST_ENTITY_H
#define GAMETEST_ENTITY_H

#include <string>

class Entity {
    std::string name;
    int health;
public:
    Entity(std::string, int health);
    std::string getName();
    int getHealth();
    int takeDamage(int);
};
#endif //GAMETEST_ENTITY_H
