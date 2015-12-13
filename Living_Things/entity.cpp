//
// Created by thoma on 9/10/2015.
//

#include "entity.h"

Entity::Entity(std::string name, int health,int stamina, int quickness, int armor, int damage) {
    this->name = name;
    this->health = health;
    this->max_health = health;
    this->stamina = stamina;
    this->quickness = quickness;
    this->armor = armor;
    this->damage = damage;
    inventory = new Inventory("inventory");
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

int Entity::getDamage() {
    return damage;
}

int Entity::takeDamage(int base_damage, int attackQuickness) {
    //TODO make the damage sort of a range, and randomly choose from between these ranges
    int dodge_chance = getChanceToDodge(attackQuickness);
    int randomNumber = getRandomNumber(100);
    stamina --;
    if(dodge_chance>=randomNumber){
        return -1;
    }
    else{
        int hurt = base_damage - armor;
        health = health - hurt;
        return hurt;
    }
}

int Entity::getChanceToDodge(int attackQuickness) {
    int dodge_chance = quickness - attackQuickness - inventory->getWeight();
    return dodge_chance;
}

int Entity::getRandomNumber(int max) {
    std::random_device* randomDevice = new std::random_device();
    int randomNumber = randomDevice->operator()() % max;
    delete randomDevice;
    return randomNumber;
}

Inventory *Entity::getInventory() {
    return inventory;
}

void Entity::heal(int heal_amount) {
    health = health + heal_amount;
    if (health > max_health){
        health = max_health;
    }
}

int Entity::getMaxHealth() {
    return max_health;
}

float Entity::getHealthPercentage() {
    return (float)health / (float)max_health;
}

void Entity::takeDamage(int base_damage) {
    health = health - base_damage;
}
