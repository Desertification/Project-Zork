//
// Created by alex on 10/31/15.
//

#include "CommandInterpreter.h"

CommandInterpreter::CommandInterpreter(Room* current_room, int* exit){
    this->current_room = current_room;
    this->exit = exit;
}

void CommandInterpreter::interpretInput(std::string input) {
    //split the string
    std::vector<std::string> stringVector= split(input, ' ');

    //to exit the application, both the first and last word need to be exit, to allow for later implementation of
    //something like "exit dungeon"
    if(stringVector.front() == "exit"){
        if(stringVector.back() == "exit"){
            *exit = 1;
        }
    }

    //if the command is go
    else if(stringVector.front() == "go"){
        std::cout << stringVector.back() << std::endl;
        if (current_room->go(stringVector.back()) == NULL) {
            std::cout << "No such room aviable" << std::endl;
        } else {
            current_room = current_room->go(stringVector.back());
            std::cout << current_room->explore();
        }
    }

    else{
        std::cout << "No such command" << std::endl;
    }
}

//split the string
std::vector<std::string> CommandInterpreter::split(const std::string &text, char sep) {
    std::vector<std::string> tokens;
    int start = 0, end = 0;
    while ((end = text.find(sep, start)) != std::string::npos) {
        tokens.push_back(text.substr(start, end - start));
        start = end + 1;
    }
    tokens.push_back(text.substr(start));
    return tokens;
}