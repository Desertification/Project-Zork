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

    //0 TODO implement death
    connections.push_back(new Connection(rooms[1], "You died", "death", rooms[0], "The forest path home",
                                         "home"));
    //1
    connections.push_back(new Connection(rooms[2], "The path towards the forest you came from", "forest", rooms[0], "The path towards the house",
                                         "house"));
    //2
    connections.push_back(new Connection(rooms[2], "There seems to be a little pathway around the house", "search", rooms[3], "The little pathway towards the front door",
                                         "back"));
    //3
    connections.push_back(new Connection(rooms[3], "Enter the kitchen", "kitchen", rooms[4], "unaviable",
                                         "back"));
    //4
    connections.push_back(new Connection(rooms[4], "There is a door in the corner", "door", rooms[5], "Go back to the kitchen",
                                         "kitchen"));
    //5
    connections.push_back(new Connection(rooms[5], "Go to the hallway", "hallway", rooms[6], "go back to the living room",
                                         "back"));
    //6
    connections.push_back(new Connection(rooms[6], "Go up the stairs", "upstairs", rooms[7], "go back downstairs",
                                         "downstairs"));
    //7
    connections.push_back(new Connection(rooms[7], "Try the doors", "doors", rooms[8], "go back to the stairs",
                                         "stairs"));
    //8
    connections.push_back(new Connection(rooms[6], "Try the doors", "doors", rooms[8], "go back to the stairs",
                                         "stairs"));
    //9
    connections.push_back(new Connection(rooms[7], "Try to cramp yourself in the food elevator", "elevator", rooms[10], "go back to the stairs",
                                         "stairs"));
    //10
    connections.push_back(new Connection(rooms[10], "Press the button to go down", "basement", rooms[11], "Press the button again",
                                         "button"));
    //11
    connections.push_back(new Connection(rooms[11], "Look for a door", "door", rooms[12], "Press the button again",
                                         "button"));
    //12
    connections.push_back(new Connection(rooms[11], "Look for a light switch", "switch", rooms[13], "Press the button again",
                                         "button"));
    //13
    connections.push_back(new Connection(rooms[12], "Look for a light switch", "switch", rooms[13], "Press the button again",
                                         "button"));
    //14
    connections.push_back(new Connection(rooms[13], "Flick the switch", "switch", rooms[14], "Press the button again",
                                         "button"));
    //15 TODO maybe make a monster appear that you have to fight
    connections.push_back(new Connection(rooms[14], "pull the brick", "pull", rooms[14], "Press the button again",
                                         "button"));
    //16
    connections.push_back(new Connection(rooms[14], "push the brick", "push", rooms[15], "Press the button again",
                                         "button"));
    //17
    connections.push_back(new Connection(rooms[15], "go into the tunnel", "tunnel", rooms[16], "Go back",
                                         "back"));
    //18
    connections.push_back(new Connection(rooms[16], "go to the book on the table", "table", rooms[17], "Go back",
                                         "back"));
    //19
    connections.push_back(new Connection(rooms[17], "go to the book in the bookcase", "bookcase", rooms[18], "Go back to the book on the table",
                                         "table"));
    //20
    connections.push_back(new Connection(rooms[16], "go to the book in the bookcase", "bookcase", rooms[18], "Go back",
                                         "back"));
    //21
    connections.push_back(new Connection(rooms[18], "go into the tunnel", "tunnel", rooms[20], "Go back",
                                         "back"));
    //22
    connections.push_back(new Connection(rooms[20], "go further into the tunnel", "further", rooms[21], "Go back",
                                         "back"));
    //23
    connections.push_back(new Connection(rooms[21], "go into the tunnel", "tunnel", rooms[22], "Go back",
                                         "back"));
    //24
    connections.push_back(new Connection(rooms[22], "go into the hole", "tunnel", rooms[23], "Go back",
                                         "back"));

    //25
    connections.push_back(new Connection(rooms[22], "go talk to the person", "tunnel", rooms[24], "Go back",
                                         "back"));

    //26 todo disable this from happening when the monster isn't dead
    connections.push_back(new Connection(rooms[22], "go further", "further", rooms[26], "Go back",
                                         "back"));
    //27
    connections.push_back(new Connection(rooms[26], "go the hostile approach", "hostile", rooms[27], "Go back",
                                         "back"));

    //28
    connections.push_back(new Connection(rooms[26], "Tell him that you are the witness", "friendly", rooms[28], "Go back",
                                         "back"));

    //29
    connections.push_back(new Connection(rooms[28], "Tell him you're here to save the world", "friendly", rooms[29], "Go back",
                                         "back"));

    //30
    connections.push_back(new Connection(rooms[29], "Decline his offer", "decline", rooms[30], "Go back",
                                         "back"));

    //31
    connections.push_back(new Connection(rooms[30], "go down the rope", "rope", rooms[31], "Go up the rope",
                                         "rope"));
    //32
    connections.push_back(new Connection(rooms[31], "go trough the window", "window", rooms[32], "Go back",
                                         "back"));
    //33
    connections.push_back(new Connection(rooms[32], "go sneak", "sneak", rooms[33], "Go back",
                                         "back"));
    //34 todo only enable this when all monsters are dead
    connections.push_back(new Connection(rooms[32], "just continue to the door", "door", rooms[34], "Go back",
                                         "back"));
    //35
    connections.push_back(new Connection(rooms[33], "just continue to the door", "door", rooms[34], "Go back",
                                         "back"));
    //36
    connections.push_back(new Connection(rooms[34], "Climb the wall", "climb", rooms[35], "Go back",
                                         "back"));
    //37
    connections.push_back(new Connection(rooms[35], "Go trough the crack", "crack", rooms[36], "Go back",
                                         "back"));
    //38
    connections.push_back(new Connection(rooms[36], "continue walking the street", "street", rooms[37], "Go back",
                                         "back"));
    //39
    connections.push_back(new Connection(rooms[37], "jump into the hole", "hole", rooms[38], "Go back",
                                         "back"));
    //40
    connections.push_back(new Connection(rooms[38], "Go trough the tiny door", "door", rooms[39], "Go back",
                                         "back"));
    //41
    connections.push_back(new Connection(rooms[39], "Rescue the Baby", "baby", rooms[40], "Go back",
                                         "back"));
    //42
    connections.push_back(new Connection(rooms[39], "Rescue the puppy", "puppy", rooms[41], "Go back",
                                         "back"));
    //43
    connections.push_back(new Connection(rooms[40], "Go trough the hole", "hole", rooms[42], "Go back",
                                         "back"));
    //44
    connections.push_back(new Connection(rooms[41], "Go trough the hole", "hole", rooms[42], "Go back",
                                         "back"));
    //45
    connections.push_back(new Connection(rooms[42], "Go up the stairs", "stairs", rooms[43], "Go back",
                                         "back"));
    //46
    connections.push_back(new Connection(rooms[43], "Continue", "further", rooms[44], "Go back",
                                         "back"));
    //47
    connections.push_back(new Connection(rooms[44], "Go to the door", "door", rooms[45], "Go back",
                                         "back"));
    //48
    connections.push_back(new Connection(rooms[45], "Go and read the poem", "read", rooms[46], "Go back",
                                         "back"));
    //49
    connections.push_back(new Connection(rooms[46], "Cry on the plant", "cry", rooms[47], "Go back",
                                         "back"));
    //50
    connections.push_back(new Connection(rooms[47], "Go down the stairs", "stairs", rooms[48], "Go back up the stairs",
                                         "stairs"));
    //51
    connections.push_back(new Connection(rooms[48], "Go to the door", "door", rooms[49], "Go back",
                                         "back"));
    //52
    connections.push_back(new Connection(rooms[49], "Explain that you are the witness", "explain", rooms[50], "Go back",
                                         "back"));
    //53
    connections.push_back(new Connection(rooms[50], "Tell it that you are here to battle evil", "tell", rooms[51], "Go back",
                                         "back"));
    //54
    connections.push_back(new Connection(rooms[51], "Accept do it a favor", "accept", rooms[52], "Go back",
                                         "back"));
    //55
    connections.push_back(new Connection(rooms[52], "Agree to give it to him", "agree", rooms[53], "Go back",
                                         "back"));
    //56
    connections.push_back(new Connection(rooms[53], "Go to the door", "door", rooms[54], "Go back",
                                         "back"));
    //57
    connections.push_back(new Connection(rooms[54], "Go to the door", "door", rooms[55], "Go back",
                                         "back"));
    //58
    connections.push_back(new Connection(rooms[55], "Go to the door", "door", rooms[56], "Go back",
                                         "back"));
    //59
    connections.push_back(new Connection(rooms[56], "Go to the door", "door", rooms[57], "Go back",
                                         "back"));
    //60
    connections.push_back(new Connection(rooms[57], "Go to the door", "door", rooms[58], "Go back",
                                         "back"));
    //61
    connections.push_back(new Connection(rooms[58], "Go to the door", "door", rooms[59], "Go back",
                                         "back"));
    //62
    connections.push_back(new Connection(rooms[59], "Go to the golden gate", "gate", rooms[60], "Go back",
                                         "back"));
    //63
    connections.push_back(new Connection(rooms[60], "Answer positive", "yes", rooms[61], "Go back",
                                         "back"));
    //64
    connections.push_back(new Connection(rooms[61], "Answer positive", "yes", rooms[62], "Go back",
                                         "back"));
    //65
    connections.push_back(new Connection(rooms[62], "Answer negative", "no", rooms[63], "Go back",
                                         "back"));
    //66
    connections.push_back(new Connection(rooms[63], "Answer negative", "no", rooms[64], "Go back",
                                         "back"));
    //67
    connections.push_back(new Connection(rooms[64], "Answer negative", "no", rooms[65], "Go back",
                                         "back"));
    //68
    connections.push_back(new Connection(rooms[65], "Go to the final gate", "gate", rooms[66], "Go back",
                                         "back"));
    //69
    connections.push_back(new Connection(rooms[66], "Give it to him", "give", rooms[67], "Go back",
                                         "back"));
    //70
    connections.push_back(new Connection(rooms[66], "Don't give it to him", "keep", rooms[68], "Go back",
                                         "back"));
    //71
    connections.push_back(new Connection(rooms[62], "Answer positive", "yes", rooms[70], "Go back",
                                         "back"));
    //72
    connections.push_back(new Connection(rooms[63], "Answer positive", "yes", rooms[70], "Go back",
                                         "back"));
    //73
    connections.push_back(new Connection(rooms[64], "Answer positive", "yes", rooms[70], "Go back",
                                         "back"));

    //the street
    rooms[0]->addConnection(connections[0]);
    rooms[0]->addConnection(connections[1]);
    //the house
    rooms[2]->addConnection(connections[1]);
    rooms[2]->addConnection(connections[2]);
    //the search
    rooms[3]->addConnection(connections[2]);
    rooms[3]->addConnection(connections[3]);
    // the kitchen
    rooms[4]->addConnection(connections[4]);
    // the living room
    rooms[5]->addConnection(connections[4]);
    rooms[5]->addConnection(connections[5]);
    // the hallway
    rooms[6]->addConnection(connections[5]);
    rooms[6]->addConnection(connections[6]);
    // the upstairs
    rooms[7]->addConnection(connections[6]);
    rooms[7]->addConnection(connections[7]);
    rooms[7]->addConnection(connections[9]);
    // the childrens bedroom
    rooms[8]->addConnection(connections[7]);
    // the food elevator
    rooms[10]->addConnection(connections[9]);
    rooms[10]->addConnection(connections[10]);
    // the basement
    rooms[11]->addConnection(connections[10]);
    rooms[11]->addConnection(connections[11]);
    rooms[11]->addConnection(connections[12]);
    // the basement dark
    rooms[12]->addConnection(connections[13]);
    // the basement lighted
    rooms[13]->addConnection(connections[14]);
    rooms[14]->addConnection(connections[15]);
    rooms[14]->addConnection(connections[16]);
    // a dark tunnel
    rooms[15]->addConnection(connections[16]);
    rooms[15]->addConnection(connections[17]);

    rooms[16]->addConnection(connections[17]);
    rooms[16]->addConnection(connections[18]);
    rooms[16]->addConnection(connections[20]);

    rooms[17]->addConnection(connections[18]);
    rooms[17]->addConnection(connections[19]);

    rooms[18]->addConnection(connections[19]);
    rooms[18]->addConnection(connections[20]);
    rooms[18]->addConnection(connections[21]);

    rooms[20]->addConnection(connections[21]);
    rooms[20]->addConnection(connections[22]);

    rooms[21]->addConnection(connections[22]);
    rooms[21]->addConnection(connections[23]);

    rooms[22]->addConnection(connections[23]);
    rooms[22]->addConnection(connections[25]);
    rooms[22]->addConnection(connections[26]);

    rooms[24]->addConnection(connections[25]);

    rooms[26]->addConnection(connections[26]);
    rooms[26]->addConnection(connections[27]);
    rooms[26]->addConnection(connections[28]);

    rooms[28]->addConnection(connections[29]);
    rooms[29]->addConnection(connections[30]);

    rooms[30]->addConnection(connections[31]);

    rooms[31]->addConnection(connections[31]);
    rooms[31]->addConnection(connections[32]);

    rooms[32]->addConnection(connections[32]);
    rooms[32]->addConnection(connections[33]);
    rooms[32]->addConnection(connections[34]);

    rooms[33]->addConnection(connections[35]);

    rooms[34]->addConnection(connections[36]);

    rooms[35]->addConnection(connections[36]);
    rooms[35]->addConnection(connections[37]);

    rooms[36]->addConnection(connections[37]);
    rooms[36]->addConnection(connections[38]);

    rooms[37]->addConnection(connections[38]);
    rooms[37]->addConnection(connections[39]);

    rooms[38]->addConnection(connections[39]);
    rooms[38]->addConnection(connections[40]);

    rooms[39]->addConnection(connections[40]);
    rooms[39]->addConnection(connections[41]);
    rooms[39]->addConnection(connections[42]);

    rooms[40]->addConnection(connections[43]);

    rooms[41]->addConnection(connections[44]);

    rooms[42]->addConnection(connections[44]);
    rooms[42]->addConnection(connections[45]);

    rooms[43]->addConnection(connections[45]);
    rooms[43]->addConnection(connections[46]);

    rooms[44]->addConnection(connections[46]);
    rooms[44]->addConnection(connections[47]);

    rooms[45]->addConnection(connections[47]);
    rooms[45]->addConnection(connections[47]);

    rooms[46]->addConnection(connections[48]);
    rooms[46]->addConnection(connections[49]);

    rooms[47]->addConnection(connections[49]);
    rooms[47]->addConnection(connections[50]);

    rooms[48]->addConnection(connections[50]);
    rooms[48]->addConnection(connections[51]);

    rooms[49]->addConnection(connections[51]);
    rooms[49]->addConnection(connections[52]);

    rooms[50]->addConnection(connections[53]);

    rooms[51]->addConnection(connections[54]);

    rooms[52]->addConnection(connections[55]);

    rooms[53]->addConnection(connections[56]);

    rooms[54]->addConnection(connections[56]);
    rooms[54]->addConnection(connections[57]);

    rooms[55]->addConnection(connections[57]);
    rooms[55]->addConnection(connections[58]);

    rooms[56]->addConnection(connections[58]);
    rooms[56]->addConnection(connections[59]);

    rooms[57]->addConnection(connections[59]);
    rooms[57]->addConnection(connections[60]);

    rooms[58]->addConnection(connections[60]);
    rooms[58]->addConnection(connections[61]);

    rooms[59]->addConnection(connections[61]);
    rooms[59]->addConnection(connections[62]);

    rooms[60]->addConnection(connections[62]);
    rooms[60]->addConnection(connections[63]);

    rooms[61]->addConnection(connections[64]);

    rooms[62]->addConnection(connections[65]);
    rooms[62]->addConnection(connections[71]);

    rooms[63]->addConnection(connections[66]);
    rooms[63]->addConnection(connections[72]);

    rooms[64]->addConnection(connections[67]);
    rooms[64]->addConnection(connections[73]);

    rooms[65]->addConnection(connections[68]);

    rooms[66]->addConnection(connections[69]);
    rooms[66]->addConnection(connections[70]);



    //add all the monsters
    spider = new Monster("spider", 1, 3, 20, 10, 70, 0, 2);

    //assign monsters to a room
    rooms[0]->addMonster(spider);

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
