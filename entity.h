//
// Created by thoma on 9/10/2015.
//

#ifndef GAMETEST_ENTITY_H
#define GAMETEST_ENTITY_H

#include <string>
#include <iostream>
#include <random>

class Entity {
    std::string name;
    int health;
    int stamina;
    int quickness;
    int armor;
    int damage;

    int getRandomNumber(int);
public:
    Entity(std::string, int health, int stamina, int quickness, int armor, int damage);
    std::string getName();
    int getHealth();
    int getStamina();
    int getQuickness();
    int getArmor();
    int getDamage();
    int takeDamage(int, int);
};
#endif //GAMETEST_ENTITY_H
