//
// Created by thoma on 12/10/2015.
//

#ifndef GAMETEST_CONNECTION_H
#define GAMETEST_CONNECTION_H


#include "room.h"

class Room; //forward declaration of Room

class Connection {
private:
    Room* left; //geen roomobject bij houden (verspilling van geheugen)
    Room* right; //i.p.v. dadde houden we de pointer bij!!!

    std::string left_description;
    std::string right_description;

    std::string left_instruction;
    std::string right_instruction;
public:
    Connection(Room*, std::string, std::string, Room*, std::string,std::string);
    std::string description(Room *);
    std::string instruction(Room *);
    Room* getOppositeRoom(Room *);
};


#endif //GAMETEST_CONNECTION_H
