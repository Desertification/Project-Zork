//
// Created by alex on 11/20/15.
//

#ifndef GAMETEST_COMMANDPARSER_H
#define GAMETEST_COMMANDPARSER_H


#include "Game.h"
#include "Command.h"

class CommandParser {

private:
    std::vector<Command *> commands;

public:
    CommandParser();
    ~CommandParser();
    void registerCommand(std::string key, commandPointer function);
    Command * listen(Game * game);
    std::vector<std::string> split(std::string str, char delimiter);
};


#endif //GAMETEST_COMMANDPARSER_H
