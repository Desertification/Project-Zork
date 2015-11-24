//
// Created by alex on 11/20/15.
//
#include "Game.h"

Game::Game() {
    //add the rooms and their connections
    kitchen = new Room("some dark omnious kitchen\nyou feel a chill going down your spine\n");
    hallway = new Room("some spooky hallway\nscreams echo in the distance\n");
    from_kitchen_to_cellar = new Connection(kitchen, "door to the hallway", "hallway", hallway, "door to the kitchen",
                                      "kitchen");

    kitchen->addConnection(from_kitchen_to_cellar);
    hallway->addConnection(from_kitchen_to_cellar);

    //add all the monsters
    spider = new Monster("spider", 1, 3, 20, 10, 70, 0, 2);

    kitchen->addMonster(spider);

    //the start, maybe make tutorial here, maybe even a function to load a previous game
    std::cout << "please enter the username you want to use" << std::endl;
    std::string username;
    getline(std::cin, username);
    hero = new Hero(username);
    //the first room
    current_room = kitchen;
    //CommandInterpreter interpreter(current_room, &exit, hero);
    std::cout << current_room->explore();
}

void Game::sayHello(std::vector<std::string> * params) {
    std::cout << "Dude ... HELLLLLLOOOOO ......" << std::endl;
}

void Game::sayBye(std::vector<std::string> * params) {
    std::cout << "Dude ... BE GONEEEEE ......" << std::endl;
}

void Game::go(std::vector<std::string> * params) {
    if (params->size() >= 1) {
        std::cout << "Going to room " << (*params)[0] << std::endl;
        //if the room isn't recognized
        if (current_room->go((*params)[0]) == NULL) {
            sout("No such room aviable");
        } else {
            sout("test");
            //if the room is recognized, go to the new room, and explore it
            current_room = current_room->go((*params)[0]);
            std::cout << current_room->explore();
        }
    }
}

void Game::show(std::vector<std::string> *params) {
    //return all available commands
    if ((*params)[0] == "commands") {
        showPossibleCommands();
    }

        //show a random number, going to let this in the code as a kind of easter egg
    else if ((*params)[0] == "random") {
        std::random_device *randomDevice = new std::random_device();
        std::cout << randomDevice->operator()() << std::endl;
        std::cout << randomDevice->operator()() % 100 << std::endl; //between 0 and 100
        delete randomDevice;
    }
    else {
        sout("No such command");
    }
}

void Game::showPossibleCommands(){
    std::vector<std::string> possibleCommands;
    //show special commands
    possibleCommands.push_back("\"show commands\"");
    //show all possible rooms
    std::vector<Connection *> *connections = current_room->getConnections();
    for (Connection *connection : *connections) {
        std::string commando = "\"go " + connection->instruction(current_room) + "\"";
        possibleCommands.push_back(commando);
    }
    //show all possible monsters
    std::vector<Monster *> *monsters = current_room->getMonsters();
    for (Monster *monster : *monsters) {
        std::string commando = "\"attack " + monster->getName() + "\"";
        possibleCommands.push_back(commando);
    }
    possibleCommands.push_back("\"exit\"");

    //print all this stuff
    for (std::string command: possibleCommands) {
        sout(command);
    }
}

void Game::sout(std::string message) {
    std::cout << message << std::endl;
}