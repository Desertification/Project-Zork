#include <iostream>
#include <sstream>
#include "room.h"
#include "CommandInterpreter.h"

using namespace std;

int main() {
    Room kitchen("some dark omnious kitchen\nyou feel a chill going down your spine\n");
    Room hallway("some spooky hallway\nscreams echo in the distance\n");
    Connection from_kitchen_to_cellar (&kitchen, "door to the hallway", "hallway", &hallway, "door to the kitchen", "kitchen");

    kitchen.addConnection(&from_kitchen_to_cellar);
    hallway.addConnection(&from_kitchen_to_cellar);

    int exit = 0;
    Room* current_room = &kitchen;
    CommandInterpreter interpreter(current_room, &exit);
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