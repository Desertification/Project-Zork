//
// Created by alex on 11/18/15.
//

#include "Monster.h"

Monster::Monster(std::string name, unsigned int id, int aggressiveness, int health, int stamina, int quickness, int armor, int damage)
    : Entity(name, health, stamina, quickness, armor, damage){
    this->aggressiveness = aggressiveness;
    this->id = id;
    inventory->setName("cropse"); // assume monster is dead when you access its inventory
}

int Monster::getAggressiveness() {
    return aggressiveness;
}

void Monster::killed() {
    aggressiveness = -1;
}

unsigned int Monster::getId() {
    return id;
}