//
// Created by thoma on 9/10/2015.
//

#ifndef GAMETEST_ENTITY_H
#define GAMETEST_ENTITY_H

#include <string>
#include <iostream>
#include <random>
#include "../Inventory.h"
class Inventory;
class Entity {
    std::string name;
    int health;
    int max_health;
    int stamina;
    int quickness;
    int armor;
    int damage;
    int getRandomNumber(int);
protected:
    Inventory* inventory;
public:
    Entity(std::string, int health, int stamina, int quickness, int armor, int damage);
    std::string getName();
    int getChanceToDodge(int attackQuickness);
    int getHealth();
    int getMaxHealth();
    float getHealthPercentage();
    int getStamina();
    int getQuickness();
    int getArmor();
    int getDamage();
    void takeDamage(int base_damage);
    int takeDamage(int base_damage, int attackQuickness);
    void heal(int heal_amount);
    Inventory* getInventory();
};
#endif //GAMETEST_ENTITY_H
