//
// Created by thomas on 12/13/15.
//

#include "HealthItem.h"

HealthItem::HealthItem(std::string name, std::string description, int weight, int health_modifier) : ConsumableItem(name,description,weight) {
    this->health_modifier = health_modifier;
}

void HealthItem::consume(Entity *user) {
    if (health_modifier >= 0){
        user->heal(health_modifier);
    }
    else {
        user->takeDamage(0-health_modifier);
    }
}
