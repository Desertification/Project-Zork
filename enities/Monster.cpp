//
// Created by alex on 11/18/15.
//

#include "Monster.h"

Monster::Monster(std::string name, int aggressiveness, int health, int stamina, int quickness, int armor, int damage)
    : Entity(name, health, stamina, quickness, armor, damage){
    this->aggressiveness = aggressiveness;
    inventory->setName(name + "_corpse"); // assume monster is dead when you access its inventory
}

int Monster::getAggressiveness() {
    return aggressiveness;
}

void Monster::killed() {
    aggressiveness = -1;
}

