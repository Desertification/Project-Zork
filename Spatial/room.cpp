//
// Created by thoma on 12/10/2015.
//

#include "room.h"

Room::Room(std::string description) {
    this->description = description;
}
std::string Room::explore() {
    // dump environment, connections and instructions in the console
    std::string result = "You are in: \n\r";
    result += description;
    result += "You see: \r\n";
    // iterate every connection the room has (also instruction)
    for (unsigned int i = 0; i < connections.size(); i++) {
        result += connections[i]->description(this) + "\r\n";
        result += "INSERT: \"go " + connections[i]->instruction(this) + "\" to go there \r\n";
    }
    return result;
}
void Room::addConnection(Connection * connection) {
    //should we check for duplicate connections?
    connections.push_back(connection);
}
Room* Room::go(std::string instruction) {
    // function to return the pointer to the next room the user wants to go to
    unsigned int i = 0;
    // iterate until index room found or no room found
    while (i < connections.size() && connections[i]->instruction(this) != instruction) { // we are using lazy evaluation here
        i++;
    }
    if (i < connections.size()) {
        return connections[i]->getOppositeRoom(this);
    }
    return NULL; // todo call explore on the new room
}

std::vector<Connection*>* Room::getConnections(){
    return &connections;
}

void Room::addMonster(Monster * monster) {
    monsters.push_back(monster);
}

std::vector<Monster*>* Room::getMonsters() {
    return &monsters;
}

void Room::addInventory(Inventory* inventory) {
    inventories.push_back(inventory);
}

std::vector<Inventory *> *Room::getInventories() {
    return &inventories;
}

Inventory *Room::getInventory(std::string name) {
    Inventory* inventory = nullptr;
    for (auto value : inventories) {
        if (value->getName() == name) {
            inventory = value;
            break;
        }
    }
    return inventory;
}

void Room::removeInventory(std::string name) {
    for (int i = 0; i < inventories.size(); ++i) {
        if (inventories[i]->getName() == name){
            delete(inventories[i]); // removes from heap
            inventories.erase(inventories.begin() + i); // removes pointer in the vector
            break;
        }
    }
}
