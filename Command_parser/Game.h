//
// Created by alex on 11/20/15.
//

#ifndef GAMETEST_GAME_H
#define GAMETEST_GAME_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "../Living_Things/Monster.h"
#include "../Spatial/connection.h"
#include "../Living_Things/Hero.h"

class Game {
private:
    Room * kitchen;
    Room * hallway;
    Connection * from_kitchen_to_cellar;

    Monster *spider;

    Room* current_room;
    Hero* hero;


    void sout(std::string message);
    void showPossibleCommands();
public:
    Game();

    void sayHello(std::vector<std::string> * params);
    void sayBye(std::vector<std::string> * params);
    void go(std::vector<std::string> * params);
    void show(std::vector<std::string> * params);


};


// Make type of command function pointer
typedef void (Game::*commandPointer)(std::vector<std::string> *);


#endif //GAMETEST_GAME_H
