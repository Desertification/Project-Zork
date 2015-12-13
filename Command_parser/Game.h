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
    std::vector<Room *> rooms;
    std::vector<Connection *> connections;

    Monster *spider;

    Room* current_room;
    Hero* hero;

    int * quit;

    int status = 0; //status = 0 when in normal mode, 1 when in combat mode, 2 when in inventory
    int previous_status = 0; // when returning from inventory

    void sout(std::string message);
    void showPossibleCommands();

    //all stuff for the combat
    void inCombat();
    Monster *combatMoster; //the last monster you were in combat with
    Inventory* globalInventory; // to store the selected inventory
    void damageGiven(int givenDamage);
public:
    Game(int * exit);

    void sayHello(std::vector<std::string> * params);
    void sayBye(std::vector<std::string> * params);
    // move between rooms
    void go(std::vector<std::string> * params);
    // command related commands
    void show(std::vector<std::string> * params);
    // exit game
    void exit(std::vector<std::string> * params);
    //all combat related commands
    void attack(std::vector<std::string> * params); //go in combat
    //all inventory related commands
    void search(std::vector<std::string> * params); // search some inventory
    // returns vector of inventories the player can access at that time
    std::vector<Inventory*> getAllReachableInventories();

};


// Make type of command function pointer
typedef void (Game::*commandPointer)(std::vector<std::string> *);


#endif //GAMETEST_GAME_H
