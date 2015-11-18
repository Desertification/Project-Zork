//
// Created by alex on 10/31/15.
//

#ifndef GAMETEST_COMMANDINTERPRETER_H
#define GAMETEST_COMMANDINTERPRETER_H


#include <string>
#include <vector>
#include <iostream>
#include <random>
#include "room.h"
#include "Hero.h"


class CommandInterpreter {
private:
    Room* current_room;
    int* exit;
    Hero* hero;
public:
    CommandInterpreter(Room*, int*, Hero*);
    void interpretInput(std::string);
    std::vector<std::string> getPossibleCommands();
    std::vector<std::string> split(const std::string &text, char sep);
    void sout(std::string message);
};


#endif //GAMETEST_COMMANDINTERPRETER_H
