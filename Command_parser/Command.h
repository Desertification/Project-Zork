//
// Created by alex on 11/20/15.
//

#ifndef GAMETEST_COMMAND_H
#define GAMETEST_COMMAND_H

#include "../Game.h"

class Command {
public:
    std::string key;
    commandPointer function;

public:
    Command(std::string key, commandPointer function);
};


#endif //GAMETEST_COMMAND_H
