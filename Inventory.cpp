//
// Created by thoma on 25/11/2015.
//

#include "Inventory.h"

Inventory::Inventory(std::string name) {
    this -> name = name;
    itemlist.resize(10);
}

int Inventory::getWeight() {
    return weight;
}

void Inventory::removeItem(std::string name) {
    for (auto &item : itemlist) {
        if (item->getName() == name) {
            delete item;
            break;
        }
    }
}

void Inventory::addItem(Item* item) {
    itemlist.push_back(item);
}

Item* Inventory::getItem(std::string name) {
    Item *test = nullptr;
    for (auto &item : itemlist) {
        if (item->getName() == name) {
            test = item;
            break;
        }
    }
    return test;
}