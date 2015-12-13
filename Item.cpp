//
// Created by thoma on 25/11/2015.
//

#include "Item.h"
#include "Lib.h"

Item::Item(std::string name, std::string description, int weight) {
    this->name = name;
    this->description = description;
    this->weight = weight;
}

std::string Item::getName() {
    return name;
}

std::string Item::getDescription() {
    return description;
}

int Item::getWeight() {
    return weight;
}

bool Item::isSwingable() {
    return swingable;
}

bool Item::isUsable() {
    return usable;
}

bool Item::isEquipable() {
    return equipable;
}

bool Item::isConsumable() {
    return consumable;
}

void Item::swing(Entity *user, Entity *monster) {
    println("You are trying your best to swing " + name + ", but it has no effect");
}

void Item::use(Entity *user, Room* room) {
    println("You are trying your best to use " + name + ", but how?");
}

void Item::equip(Entity *user) {
    println("How would you even equip " + name);
}

void Item::consume(Entity *user) {
    println("Didn't your mother learn yo to not stick random stuff in your mouth");
}
