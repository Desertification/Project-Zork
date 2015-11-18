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
        //if the room isn't recognized
        if (current_room->go(stringVector.back()) == NULL) {
            std::cout << "No such room aviable" << std::endl;
        } else {
            //if the room is recognized, go to the new room, and explore it
            current_room = current_room->go(stringVector.back());
            std::cout << current_room->explore();
        }
    }

    //if the command is get
    else if(stringVector.front()=="show"){
        //return all available commands
        if(stringVector.back()=="commands"){
            std::vector<std::string> possibleCommands = getPossibleCommands();
            for(std::string command: possibleCommands){
                std::cout << command << std::endl;
            }
        }

        //show a random number, going to let this in the code as a kind of easter egg
        if(stringVector.back()=="random"){
            std::random_device* randomDevice = new std::random_device();
            std::cout << randomDevice->operator()() << std::endl;
            std::cout << randomDevice->operator()() % 100 << std::endl; //between 0 and 100
            delete randomDevice;
        }
    }

    else{
        std::cout << "No such command" << std::endl;
    }
}

std::vector<std::string> CommandInterpreter::getPossibleCommands() {
    std::vector<std::string> possibleCommands;
    //show special commands
        possibleCommands.push_back("\"show commands\"");
        //show all possible rooms
        std::vector<Connection*>* connections = current_room->getConnections();
        for(Connection* connection : *connections){
            std::string commando = "\"go " +connection->instruction(current_room) + "\"";
            possibleCommands.push_back(commando);
        }
        possibleCommands.push_back("\"exit\"");
    return possibleCommands;
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