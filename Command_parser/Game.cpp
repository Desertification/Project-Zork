//
// Created by alex on 11/20/15.
//
#include "Game.h"



void Game::init() {
    //add the rooms and their connections
    Room kitchen("some dark omnious kitchen\nyou feel a chill going down your spine\n");
    Room hallway("some spooky hallway\nscreams echo in the distance\n");
    Connection from_kitchen_to_cellar(&kitchen, "door to the hallway", "hallway", &hallway, "door to the kitchen",
                                      "kitchen");

    kitchen.addConnection(&from_kitchen_to_cellar);
    hallway.addConnection(&from_kitchen_to_cellar);

    //add all the monsters
    Monster *spider = new Monster("spider", 1, 3, 20, 10, 70, 0, 2);

    kitchen.addMonster(spider);

    //the start, maybe make tutorial here, maybe even a function to load a previous game
    std::cout << "please enter the username you want to use" << std::endl;
    std::string username;
    getline(std::cin, username);
    hero = new Hero(username);
    //the first room
    current_room = &kitchen;
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
    }
}