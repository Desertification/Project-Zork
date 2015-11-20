/*#include <iostream>
#include <sstream>
#include "room.h"
#include "CommandInterpreter.h"

using namespace std;


//TODO put all this stuff in another class
int main() {
    Room kitchen("some dark omnious kitchen\nyou feel a chill going down your spine\n");
    Room hallway("some spooky hallway\nscreams echo in the distance\n");
    Connection from_kitchen_to_cellar (&kitchen, "door to the hallway", "hallway", &hallway, "door to the kitchen", "kitchen");

    kitchen.addConnection(&from_kitchen_to_cellar);
    hallway.addConnection(&from_kitchen_to_cellar);

    //monsters
    Monster* spider = new Monster("spider", 1, 3, 20, 10, 70,0,2);
    kitchen.addMonster(spider);

    //the start, maybe make tutorial here, maybe even a function to load a previous game
    cout << "please enter the username you want to use" << endl;
    string username;
    getline(cin, username);
    Hero* hero = new Hero(username);

    //the standard game
    int exit = 0;
    Room* current_room = &kitchen;
    CommandInterpreter interpreter(current_room, &exit, hero);
    cout << current_room->explore();

    while(exit == 0) {
        //define command string, and get the input
        string command;
        getline(cin, command);
        //interpret the input
        interpreter.interpretInput(command);
    }

    return 0;
}
 */

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "Game.h"
#include "Command_parser/Command.h"

using namespace std;

// Source: http://code.runnable.com/VHb0hWMZp-ws1gAr/splitting-a-string-into-a-vector-for-c%2B%2B
vector<string> split(string str, char delimiter) {
    vector<string> internal;
    stringstream ss(str); // Turn the string into a stream.
    string tok;

    while(getline(ss, tok, delimiter)) {
        internal.push_back(tok);
    }

    return internal;
}



class CommandParser {

private:
    std::vector<Command *> commands;

public:
    CommandParser();
    ~CommandParser();
    void registerCommand(std::string key, commandPointer function);
    Command * listen(Game * game);
};

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
    vector<string> params = split(line, ' ');

    int i = 0;
    while (i < commands.size() &&
           commands[i]->key.compare(params[0]) != 0) {

        i++;
    }

    if (i < commands.size()) {
        cout << "Command found, You typed " << line << endl;
        params.erase(params.begin());   // Remove actual command


        commandPointer ptr = commands[i]->function;

        (*game.*ptr)(&params);
        // (*this.*(commands[i]->function(&params));
    } else {
        cout << "Unknown command" << endl;
    }


    return NULL;
}


int main(void) {

    CommandParser parser;
    Game game;

    parser.registerCommand("sayhello", &Game::sayHello);
    parser.registerCommand("saybye", &Game::sayBye);
    parser.registerCommand("go", &Game::go);

    parser.listen(&game);

    return 0;

}