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
    std::vector<Item*>::iterator it;
    for (it = inventory.begin(); it != inventory.end(); it++){
        if((*it)->getName() == name){
            delete *it;
            inventory.erase(it);
            break;
        }
    }
}

void Inventory::removeItem(int index) {
    std::vector<Item*>::iterator it;
    int i = 0;
    for(it = inventory.begin(); it != inventory.end() ; it++,i++) {
        if(i == index){
            delete *it; //delete object?
            inventory.erase(it); //remove pointer
            break;
        }
    }
}

void Inventory::addItem(Item* item) {
    inventory.push_back(item);
}

Item* Inventory::getItem(std::string name) {
    std::vector<Item*>::iterator it;
    for (it = inventory.begin(); it != inventory.end(); it++){
        if((*it)->getName() == name){
            break;
        }
    }
    return *it;
}

Item* Inventory::getItem(int index) {
    std::vector<Item*>::iterator it;
    int i = 0;
    for(it = inventory.begin(); it != inventory.end() ; it++,i++) {
        if(i == index){
            break;
        }
    }
    return *it;
}