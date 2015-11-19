#include <iostream>
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