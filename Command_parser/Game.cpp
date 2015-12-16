//
// Created by alex on 11/20/15.
//
#include "Game.h"
#include "../Lib.h"
#include "../Items/Apple.h"
#include "../Map.h"

Game::Game(int *exit) {
    //create all the stuff in the most non oop way

    //add the rooms and their connections
    rooms = getRooms();

    connections = getConnections(rooms);

    addConnectionsToRooms(rooms, connections);


    //add all the monsters
    spider = new Monster("spider", 1, 3, 20, 10, 70, 0, 2);
    //the monster that kills you when you enter a forbidden room
    killed = new Monster("the grim reaper", 2, 3, 9001,9001,9001,9001,9001);

    //assign monsters to a room
    rooms[0]->addMonster(spider);

    //assign killed
    rooms[1]->addMonster(killed);
    rooms[24]->addMonster(killed);
    rooms[43]->addMonster(killed);
    rooms[68]->addMonster(killed);
    rooms[70]->addMonster(killed);
    rooms[71]->addMonster(killed);
    rooms[72]->addMonster(killed);
    rooms[76]->addMonster(killed);



    //the start, maybe make tutorial here, maybe even a function to load a previous game
    std::cout << "please enter the username you want to use" << std::endl;
    std::string username;
    getline(std::cin, username);
    hero = new Hero(username);
    hero->getInventory()->addItem(new Apple());

    //the first room
    current_room = rooms[0];
    //CommandInterpreter interpreter(current_room, &exit, hero);
    std::cout << current_room->explore();
    this->quit = exit;
}
// todo replace with Lib println to be replaced by gui function
void Game::sout(std::string message) {
    std::cout << message << std::endl;
}

void Game::exit(std::vector<std::string> *params) {
    *quit = 1;
}

void Game::inCombat() {
    sout("I'm sorry, i can't let you do that while you're in combat.");
}

//TODO show the possible commands for all combat options
void Game::showPossibleCommands() {

    std::vector<std::string> possibleCommands;
    //show special commands
    possibleCommands.push_back("\"show commands\"");

    if (status == 0){ // only when in normal mode
        //show all possible rooms
        std::vector<Connection *> *connections = current_room->getConnections();
        for (Connection *connection : *connections) {
            std::string commando = "\"go " + connection->instruction(current_room) + "\"";
            possibleCommands.push_back(commando);
        }
        //show all possible monsters
        std::vector<Monster *> *monsters = current_room->getMonsters();
        for (Monster *monster : *monsters) {
            if (monster->getAggressiveness() != -1){
                std::string commando = "\"attack " + monster->getName() + "\"";
                possibleCommands.push_back(commando);
            }
        }
        // equip armor
        if (hero->getItem()){
            possibleCommands.push_back("\"equip " + hero->getItem()->getName() + "\"");
        }
        // use item (key like functionality)
        if (hero->getItem()){
            possibleCommands.push_back("\"use " + hero->getItem()->getName() + "\"");
        }
    }
    else if (status == 1) { // when in combat
        //show all possible attacks
        possibleCommands.push_back("\"attack strong\""); // fixme would punch fit better here?
        possibleCommands.push_back("\"attack fast\"");
        if (hero->getItem()){
            possibleCommands.push_back("\"swing " + hero->getItem()->getName() + "\"");
        }
    }

    if (status == 0 or status == 1) { // when in combat or normal
        //show all possible inventories to search)
        std::vector<Inventory *> inventories = getAllReachableInventories();
        for (auto value : inventories) {
            std::string command = "\"search " + value->getName() + "\"";
            possibleCommands.push_back(command);
        }
        //show item commands
        if (hero->getItem()) {
            std::string itemname = hero->getItem()->getName();
            possibleCommands.push_back("\"drop " + itemname + "\"");
            possibleCommands.push_back("\"consume " + itemname + "\"");
            possibleCommands.push_back("\"info " + itemname + "\"");
        }
    }

    if (status == 2) { // when in an inventory
        // show all possible items to grab
        for (auto value : *selectedInventory->getItems()) {
            std::string command = "\"grab " + value->getName() + "\"";
            possibleCommands.push_back(command);
        }
        // leave inventory command
        possibleCommands.push_back("\"leave " + selectedInventory->getName() + "\"");
    }

    possibleCommands.push_back("\"exit\"");

    //print all this stuff
    for (std::string command: possibleCommands) {
        sout(command);
    }

}

void Game::damageGiven(int givenDamage) {
    if (givenDamage == -1) {
        sout(combatMoster->getName() + " dodged your attack");
    } else {
        sout("you dealt " + std::to_string(givenDamage) + " to " + combatMoster->getName());
        if (combatMoster->getHealth() <= 0) {
            //set the monster as killed
            combatMoster->killed();
            sout("you have triumphed over your enemy");
            status = 0;
        }else{
            sout(combatMoster->getName() + " now has " + std::to_string(combatMoster->getHealth()) + " hp left");
        }
    }
    //first check if you are still in combat (in case the monster is already dead)
    if (status == 1){
        givenDamage =  hero->takeDamage(combatMoster->getDamage(), hero->getQuickness());
        if (givenDamage == -1) {
            sout("you dodged an attack from " + combatMoster->getName());
        } else {
            sout(combatMoster->getName()+ " dealt " + std::to_string(givenDamage) + " to you");
            if (hero->getHealth() <= 0) {
                *quit = 1;
                sout("GAME OVER YOU DAMN NOOB");
            } else {
                sout("You now have " + std::to_string(hero->getHealth()) + " hp left");
            }
        }
    }

}

void Game::sayHello(std::vector<std::string> *params) {
    //switch for when in combat
    switch (status) {
        case 1:
            inCombat();
            break;
        default:
            std::cout << "Dude ... HELLLLLLOOOOO ......" << std::endl;
    }
}

void Game::sayBye(std::vector<std::string> *params) {
    switch (status) {
        case 1:
            inCombat();
            break;
        default:
            std::cout << "Dude ... BE GONEEEEE ......" << std::endl;
    }
}

void Game::go(std::vector<std::string> *params) {
    switch (status) {
        case 1:
            inCombat();
            break;
        default:
            if (params->size() >= 1) {
                std::cout << "Going to room " << (*params)[0] << std::endl;
                //if the room isn't recognized
                if (current_room->go((*params)[0]) == NULL) {
                    sout("No such room aviable");
                } else {
                    //if the room is recognized, go to the new room, and explore it
                    current_room = current_room->go((*params)[0]);
                    std::cout << current_room->explore();
                    //automatically enter combat when there are monsters with aggresiveness level 3 in the room
                    std::vector<Monster *> *monsters = current_room->getMonsters();
                    int aggrasiveMonster = false;
                    for (Monster *monster : *monsters) {
                        if (monster->getAggressiveness()==3){
                            aggrasiveMonster = true;
                            combatMoster = monster;
                        }
                    }
                    if(aggrasiveMonster == true){
                        sout("A monster attacked you when you entered the room");
                        status = 1;
                    }
                }
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

void Game::attack(std::vector<std::string> *params) {
    switch (status) {
        case 1:
            if ((*params)[0]=="fast") {
                int givenDamage = combatMoster->takeDamage(hero->getDamage(), hero->getQuickness());
                damageGiven(givenDamage);
            }
            else if ((*params)[0]=="strong"){
                int givenDamage = combatMoster->takeDamage(hero->getDamage() * 2, hero->getQuickness() / 2);
                damageGiven(givenDamage);
            }
            else{
                sout("You can't attack that way");
            }
            break;
        default:
            //get all the monsters in the current room
            std::vector<Monster *> *monsters = current_room->getMonsters();
            //check if the monster is in the room
            unsigned int contains = 0;
            for (Monster *monster : *monsters) {
                if (monster->getName() == (*params)[0]) {
                    combatMoster = monster;
                    //check if the monster isn't dead
                    if (combatMoster->getAggressiveness()!= -1){
                        contains = 1;
                    } else {
                        contains = 2;
                    }

                }
            }

            if (contains == 1) {
                status = 1;
                sout("you are now in combat");

                sout(std::string("attack fast (damage :") +
                     std::to_string(hero->getDamage() - combatMoster->getArmor()) + " chance to hit : " +
                     std::to_string(
                             100 - combatMoster->getChanceToDodge(hero->getQuickness())) + " %)");
                sout("INSERT: \"attack fast\" for a normal attack");
                sout(std::string("attack strong (damage :") +
                     std::to_string(hero->getDamage() * 2 - combatMoster->getArmor()) + " chance to hit : " +
                     std::to_string(
                             100 - combatMoster->getChanceToDodge(hero->getQuickness() / 2)) + " %)");
                sout("INSERT: \"attack strong\" for a strong attack");
                sout("the enemy has " + std::to_string(combatMoster->getHealth()) + " hp");
                sout("You have " + std::to_string(hero->getHealth()) + " hp");
            } else if (contains == 2){
                sout("that monster is already dead");
            }else {
                sout("no such monster aviable");
            }
    }
}

void Game::search(std::vector<std::string> *params) { //TODO grab commands / use commands
    std::vector<Inventory *> test = getAllReachableInventories();
    for (auto value : test) {
        if (value->getName() == (*params)[0]) {
            if (value->isEmpty()) {
                println("Nothing to be found here");
            }
            else {
                selectedInventory = value;
                previous_status = status;
                status = 2;
                println(value->getName() + " contains:");
                for (auto value : *selectedInventory->getItems()){
                    println(value->getName());
                }
            }
        }
        else {
            println("No such inventory found");
        }
    }
}

std::vector<Inventory *> Game::getAllReachableInventories() {
    std::vector<Inventory*> inventories;{
        inventories.push_back(hero->getInventory());
        if (status == 0){ // while in combat, your backpack is the only thing in range
            std::vector<Inventory*>* room_Inventories = current_room->getInventories();
            inventories.insert(inventories.begin(),room_Inventories->begin(),room_Inventories->end());//IDE marking bug
            for (auto value : *current_room->getMonsters()){
                if (value->getAggressiveness() == -1){
                    inventories.push_back(value->getInventory());
                }
            }
        }
    }
    return inventories;
}

void Game::grab(std::vector<std::string> *params) {
    if (status == 2){
        for (auto value : *selectedInventory->getItems()){
            if (value->getName() == (*params)[0]){
                hero->holdItem(value);
                selectedInventory->removeItem(value->getName());
                println("You grabed " + value->getName());
                status = previous_status;
                break;
            }
            else {
                println("Invalid item");
            }
        }
    }
    else {
        println("Invalid command");
    }
}

void Game::leave(std::vector<std::string> *params) {
    if (status == 2){
        status = previous_status;
    }
    else {
        println("Invalid command");
    }
}
// todo find a way to remove these repeated if (boilerplate code)
void Game::drop(std::vector<std::string> *params) {
    if (hero->getItem() and status != 2){
        if (hero->getItem()->getName() == (*params)[0]){
            hero->dropItem();
        }
        else {
            println("You don't hold that item");
        }
    }
    else {
        println("Invalid command");
    }
}

void Game::info(std::vector<std::string> *params) {
    if (hero->getItem() and status != 2){
        if (hero->getItem()->getName() == (*params)[0]){
            println(hero->getItem()->getDescription()); //todo more info would be nice
        }
        else {
            println("You don't hold that item");
        }
    }
    else {
        println("Invalid command");
    }
}

void Game::consume(std::vector<std::string> *params) {
    if (hero->getItem() and status != 2){
        if (hero->getItem()->getName() == (*params)[0]){
            hero->getItem()->consume(hero);
        }
        else {
            println("You don't hold that item");
        }
    }
    else {
        println("Invalid command");
    }
}

void Game::use(std::vector<std::string> *params) {
    if (hero->getItem() and status == 0){
        if (hero->getItem()->getName() == (*params)[0]){
            hero->getItem()->use(hero,current_room);
        }
        else {
            println("You don't hold that item");
        }
    }
    else {
        println("Invalid command");
    }
}

void Game::swing(std::vector<std::string> *params) {
    if (hero->getItem() and status == 1){
        if (hero->getItem()->getName() == (*params)[0]){
            hero->getItem()->swing(hero,combatMoster);
        }
        else {
            println("You don't hold that item");
        }
    }
    else {
        println("Invalid command");
    }
}

void Game::equip(std::vector<std::string> *params) {
    if (hero->getItem() and status == 0){
        if (hero->getItem()->getName() == (*params)[0]){
            hero->getItem()->equip(hero);
        }
        else {
            println("You don't hold that item");
        }
    }
    else {
        println("Invalid command");
    }
}
