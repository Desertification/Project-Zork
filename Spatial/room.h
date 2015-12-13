//
// Created by thoma on 12/10/2015.
//

#ifndef GAMETEST_ROOM_H
#define GAMETEST_ROOM_H


#include <string>
#include <vector>
#include "connection.h"
#include "../Living_Things/Monster.h"
#include "../Inventory.h"


class Connection; //forward declaration of room class, these classes reference each other, compiler can't compile them at the same time, so it keeps cycling between them
class Monster;
class Inventory;
class Room {
private:
    std::string description;
    std::vector <Connection*> connections;
    std::vector <Monster*> monsters;
    std::vector <Inventory*> inventories;
    // best practices vectors
    //http://stackoverflow.com/questions/141337/c-stl-should-i-store-entire-objects-or-pointers-to-objects
public:
    Room(std::string);
    std::string explore();
    void addConnection(Connection*);
    Room* go(std::string);
    std::vector<Connection*>* getConnections();
    void addMonster(Monster*);
    std::vector<Monster*>* getMonsters();
    void addInventory(Inventory* inventory);
    std::vector<Inventory*>* getInventories();
    Inventory* getInventory(std::string name);
    void removeInventory(std::string name);
};


#endif //GAMETEST_ROOM_H
