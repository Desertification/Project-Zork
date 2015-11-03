//
// Created by thoma on 9/10/2015.
//

#ifndef GAMETEST_ENTITY_H
#define GAMETEST_ENTITY_H

#include <string>

class Entity {
    std::string name;
    int health;
    int stamina;
    int quickness;
    int armor;
    int damage;
public:
    Entity(std::string, int health, int stamina, int quickness, int armor);
    std::string getName();
    int getHealth();
    int takeDamage(int, int);
};
#endif //GAMETEST_ENTITY_H
