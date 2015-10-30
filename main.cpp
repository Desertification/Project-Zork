#include <iostream>
#include "room.h"

using namespace std;

int main() {
    Room kitchen("some dark omnious kitchen\nyou feel a chill going down your spine\n");
    Room hallway("some spooky hallway\nscreams echo in the distance\n");
    Connection from_kitchen_to_cellar (&kitchen, "door to the hallway", "go hallway", &hallway, "door to the kitchen", "go kitchen");

    kitchen.addConnection(&from_kitchen_to_cellar);
    hallway.addConnection(&from_kitchen_to_cellar);


    Room* current_room = &kitchen;
    cout << current_room->explore();
    current_room = current_room->go("go hallway");
    cout << current_room->explore();

    return 0;
}