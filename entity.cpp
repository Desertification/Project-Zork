//
// Created by thoma on 9/10/2015.
//

#include <string>
#include "entity.h"

Entity::Entity(std::string name, int health,int stamina, int quickness, int armor) {
    this->name = name;
    this->health = health;
    this->stamina = stamina;
    this->quickness = quickness;
    this->armor = armor;
}


int Entity::getHealth() {
    return health;
}
std::string Entity::getName() {
    return name;
}
int Entity::takeDamage(int attack, int attackQuickness) {
    //return health - dammage;
}