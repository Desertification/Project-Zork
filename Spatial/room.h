//
// Created by thoma on 12/10/2015.
//

#ifndef GAMETEST_ROOM_H
#define GAMETEST_ROOM_H


#include <string>
#include <vector>
#include "connection.h"
#include "../Living_Things/Monster.h"

class Connection; //foreward declaration of room class, these classes reference each other, compiler can't compile them at the same time, so it keeps cycling between them

class Room {
private:
    std::string description;
    std::vector <Connection*> connections;
    std::vector <Monster*> monsters;
public:
    Room(std::string);
    std::string explore();
    void addConnection(Connection*);
    Room* go(std::string);
    std::vector<Connection*>* getConnections();
    void addMonster(Monster*);
    std::vector<Monster*>* getMonsters();
};


#endif //GAMETEST_ROOM_H
