//
// Created by alex on 11/20/15.
//

#include "Command.h"
#include "../Game.h"

Command::Command(std::string key, commandPointer function) {
    this->key = key;
    this->function = function;
}