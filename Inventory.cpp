//
// Created by thoma on 25/11/2015.
//

#include "Inventory.h"

Inventory::Inventory(std::string name) {
    this -> name = name;
}

int Inventory::getWeight() {
    return weight;
}

void Inventory::removeItem(std::string name) {
    for (int i = 0; i < itemlist.size(); ++i) {
        if (itemlist[i]->getName() == name){
            delete(itemlist[i]); // removes item from heap
            itemlist.erase(itemlist.begin() + i); // removes pointer to item in the vector
            break;
        }
    }
}

void Inventory::addItem(Item* item) {
    itemlist.push_back(item);
}

Item* Inventory::getItem(std::string name) {
    Item* test = nullptr; // use getItems first to check if the item exits or handle the nullptr
    for (auto item : itemlist) {
        if (item->getName() == name) {
            test = item;
            break;
        }
    }
    return test;
}

std::vector<Item *> *Inventory::getItems() {
    return &itemlist;
}

std::string Inventory::getName() {
    return name;
}

void Inventory::setName(std::string name) {
    this->name = name;
}
