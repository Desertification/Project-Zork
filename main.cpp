#include <iostream>
#include <sstream>
#include "room.h"

using namespace std;

//split the string
std::vector<std::string> split(const std::string &text, char sep) {
    std::vector<std::string> tokens;
    int start = 0, end = 0;
    while ((end = text.find(sep, start)) != std::string::npos) {
        tokens.push_back(text.substr(start, end - start));
        start = end + 1;
    }
    tokens.push_back(text.substr(start));
    return tokens;
}

int main() {
    Room kitchen("some dark omnious kitchen\nyou feel a chill going down your spine\n");
    Room hallway("some spooky hallway\nscreams echo in the distance\n");
    Connection from_kitchen_to_cellar (&kitchen, "door to the hallway", "hallway", &hallway, "door to the kitchen", "kitchen");

    kitchen.addConnection(&from_kitchen_to_cellar);
    hallway.addConnection(&from_kitchen_to_cellar);


    Room* current_room = &kitchen;
    cout << current_room->explore();
    //current_room = current_room->go("go hallway");
    //cout << current_room->explore();

    //define command string, input it, then output the input
    string command;
    getline(cin, command);

    //split the string
    vector<string> stringVector= split(command, ' ');
//  //output each word of the input
//    for (string enkele : stringVector) {
//        cout << enkele << endl;
//    }

    if(stringVector.front() == "go"){
        cout << stringVector.back() << endl;
        current_room = current_room->go(stringVector.back());
        cout << current_room->explore();
    }







    return 0;
}