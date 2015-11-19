//
// Created by alex on 11/19/15.
//

#include "CommandParser.h"

CommandParser::CommandParser() {}


CommandParser::~CommandParser() {
    for (int i = 0; i < commands.size(); i++) {
        delete commands[i];
        commands[i] = NULL;
    }

    commands.clear();
}

void CommandParser::registerCommand(std::string key, commandPointer function) {
    Command * cmd = new Command(key, function);
    commands.push_back(cmd);
}

Command * CommandParser::listen(void) {

    std::string line;
    std::getline(std::cin, line);

    // Tokenize
    vector<string> params = split(line, ' ');

    int i = 0;
    while (i < commands.size() &&
           commands[i]->key.compare(params[0]) != 0) {

        i++;
    }

    if (i < commands.size()) {
        std::cout << "Command found, You typed " << line << std::endl;
        params.erase(params.begin());   // Remove actual command
        commands[i]->function(&params);
    } else {
        std::cout << "Unknown command" << std::endl;
    }


    return NULL;
}
