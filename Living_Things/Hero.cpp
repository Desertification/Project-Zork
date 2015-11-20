//
// Created by alex on 11/2/15.
//

#include "Hero.h"


Hero::Hero(std::string name, int health, unsigned int level) : Entity(name, health, 100, 20, 0, 5) {
    this->level = level;
}

//a shorter constructor with standard create values
Hero::Hero(std::string name) : Entity(name, 100, 100, 50, 0, 5) {
    this->level = 0;
}

unsigned int Hero::getLevel() {
    return level;
}

void Hero::Levelup() {
    level++;
}