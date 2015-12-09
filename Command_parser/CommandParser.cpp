//
// Created by alex on 11/20/15.
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

Command * CommandParser::listen(Game * game) {

    std::string line;
    std::getline(std::cin, line);

    // Tokenize
    std::vector<std::string> params = split(line, ' ');

    int i = 0;
    while (i < commands.size() &&
           commands[i]->key.compare(params[0]) != 0) {

        i++;
    }

    if (i < commands.size()) {
        params.erase(params.begin());   // Remove actual command


        commandPointer ptr = commands[i]->function;

        (*game.*ptr)(&params);
        // (*this.*(commands[i]->function(&params));
    } else {
        std::cout << "Unknown command" << std::endl;
    }


    return NULL;
}

// Source: http://code.runnable.com/VHb0hWMZp-ws1gAr/splitting-a-string-into-a-vector-for-c%2B%2B
std::vector<std::string> CommandParser::split(std::string str, char delimiter) {
    std::vector<std::string> internal;
    std::stringstream ss(str); // Turn the string into a stream.
    std::string tok;

    while(getline(ss, tok, delimiter)) {
        internal.push_back(tok);
    }

    return internal;
}