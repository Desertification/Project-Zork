//
// Created by thoma on 25/11/2015.
//

#include "Item.h"

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