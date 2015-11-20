//
// Created by alex on 11/21/15.
//

#include "StartClass.h"


startClass::startClass() {
    CommandParser parser;
    Game game;

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

    //add the commands
    parser.registerCommand("sayhello", &Game::sayHello);
    parser.registerCommand("saybye", &Game::sayBye);
    parser.registerCommand("go", &Game::go);


    //the start, maybe make tutorial here, maybe even a function to load a previous game
    std::cout << "please enter the username you want to use" << std::endl;
    std::string username;
    getline(std::cin, username);
    Hero* hero = new Hero(username);

    //the standard game
    int exit = 0;
    //the first room
    Room* current_room = &kitchen;
    //CommandInterpreter interpreter(current_room, &exit, hero);
    std::cout << current_room->explore();

    while(exit == 0) {
        //listen for context
        parser.listen(&game);
    }
}