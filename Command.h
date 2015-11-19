//
// Created by alex on 11/19/15.
//

#ifndef GAMETEST_COMMAND_H
#define GAMETEST_COMMAND_H


#include <iostream>
#include <string>
#include <vector>
#include <sstream>

class Command {
public:
    std::string key;
    commandPointer function;

public:
    Command(std::string key, commandPointer function);
};


#endif //GAMETEST_COMMAND_H
