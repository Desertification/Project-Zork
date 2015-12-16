//
// Created by alex on 11/2/15.
//

#include "Hero.h"


Hero::Hero(std::string name, int health, unsigned int level) : Entity(name, health, 100, 20, 0, 5) {
    this->level = level;
    inventory->setName("backpack");
}

//a shorter constructor with standard create values
Hero::Hero(std::string name) : Entity(name, 100, 100, 50, 0, 5) {
    // todo: way to not repeat these statements
    // solution(constructor delegation) might not be supported: http://stackoverflow.com/questions/7330296/constructor-overloading-in-c
    this->level = 0;
    inventory = new Inventory("backpack");
}

unsigned int Hero::getLevel() {
    return level;
}

void Hero::Levelup() {
    level++;
}