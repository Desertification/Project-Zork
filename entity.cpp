//
// Created by thoma on 9/10/2015.
//

#include "entity.h"

Entity::Entity(std::string name, int health,int stamina, int quickness, int armor, int damage) {
    this->name = name;
    this->health = health;
    this->stamina = stamina;
    this->quickness = quickness;
    this->armor = armor;
    this->damage = damage;
}


int Entity::getHealth() {
    return health;
}

int Entity::getStamina() {
    return stamina;
}

int Entity::getQuickness() {
    return quickness;
}

int Entity::getArmor() {
    return armor;
}

std::string Entity::getName() {
    return name;
}
int Entity::takeDamage(int attack, int attackQuickness) {
    int dodge_chance = ( quickness *  stamina )- attackQuickness;
    int randomNumber = getRandomNumber(100);
    stamina --;
    if(dodge_chance<=randomNumber){
        return -1;
    }
    else{
        int hurt = attack - armor;
        health = health - hurt;
        return hurt;
    }
}

int Entity::getRandomNumber(int max) {
    std::random_device* randomDevice = new std::random_device();
    int randomNumber = randomDevice->operator()() % max;
    delete randomDevice;
    return randomNumber;
}