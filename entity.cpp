//
// Created by thoma on 9/10/2015.
//

#include <string>
#include "entity.h"

Entity::Entity(std::string, int health) {
    this->name = name;
    this->health = health;
}
int Entity::getHealth() {
    return health;
}
std::string Entity::getName() {
    return name;
}
int Entity::takeDamage(int dammage) {
    return health - dammage;
}