//
// Created by alex on 10/31/15.
//

#ifndef GAMETEST_COMMANDINTERPRETER_H
#define GAMETEST_COMMANDINTERPRETER_H


#include <string>
#include <vector>
#include <iostream>
#include "room.h"


class CommandInterpreter {
private:
    Room* current_room;
public:
    CommandInterpreter(Room*);
    void interpretInput(std::string);
    std::vector<std::string> split(const std::string &text, char sep);
};


#endif //GAMETEST_COMMANDINTERPRETER_H
