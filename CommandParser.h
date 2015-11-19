//
// Created by alex on 11/19/15.
//

#ifndef GAMETEST_COMMANDPARSER_H
#define GAMETEST_COMMANDPARSER_H


#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "Command.h"

class CommandParser {

private:
    std::vector<Command *> commands;

public:
    CommandParser();
    ~CommandParser();
    void registerCommand(std::string key, commandPointer function);
    Command * listen(void);
};


#endif //GAMETEST_COMMANDPARSER_H
