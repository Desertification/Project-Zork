//
// Created by alex on 11/20/15.
//
#include "Game.h"

Game::Game(int *exit) {
    //create all the stuff
    //add the rooms and their connections

    //0 outside on the street
    rooms.push_back(new Room("You see a house in the distance..\nMaybe you'll find shelter in there from the dark and the rain\n"));
    //1 walk on TODO implement death
    rooms.push_back(new Room("you chose to keep walking in the dark forest in the rain.\nYou have tripped over a fallen branch, hit your head and died.\n"));
    //2 the house
    rooms.push_back(new Room("The front door seems to be locked\nMaybe there is a back door open.\n"));
    //3 the door outside
    rooms.push_back(new Room("You see the door that leads towards the kitchen\n"));
    //4 the kitchen
    rooms.push_back(new Room("Finally shelter. And maybe, with a little luck you'll find some food in the cabins.\n"
                                     "While searching the cabins, you suddenly hear a deep voice coming from the dark saying : \n"
                                     "\"Who is it there, trying to steal from me?\"\n\n"
                                     "You answer the deep voice : \n"
                                     "\"I'm sorry, I didn't know someone was home. I...\"\n"
                                     "The voice interrupts you with his deep voice and in an angry tone :\n"
                                     "\"You shall mourn the day you walked inside! Now you're mine for eternity.\"\n"
                                     "The voice now was laughing, just laughing with you, and you never felt so scared. You wanted to get out of there, and ran towards the door.\n"
                                     "As you approached the door, the door slams, and locks. It looks like you're trapped inside."

    ));
    //5 living room
    rooms.push_back(new Room("You appear to be in the living room. \n"
                                     "All the furniture is covered in white sheets. There is a door towards what you assume is the hallway\n"));
    //6 hallway
    rooms.push_back(new Room("The front door is still locked and there doesn't appear to be a key lying around.\n"
                                     "Perhaps there is something on the first floor. I could use the stairs"));



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



    //add all the monsters
    spider = new Monster("spider", 1, 3, 20, 10, 70, 0, 2);

    //assign monsters to a room
    rooms[0]->addMonster(spider);

    //the start, maybe make tutorial here, maybe even a function to load a previous game
    std::cout << "please enter the username you want to use" << std::endl;
    std::string username;
    getline(std::cin, username);
    hero = new Hero(username);
    //the first room
    current_room = rooms[0];
    //CommandInterpreter interpreter(current_room, &exit, hero);
    std::cout << current_room->explore();

    this->quit = exit;
}

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
    switch (status) {
        case 1:
            inCombat();
            break;
        default:
            std::vector<std::string> possibleCommands;
            //show special commands
            possibleCommands.push_back("\"show commands\"");
            //show all possible rooms
            std::vector<Connection *> *connections = current_room->getConnections();
            for (Connection *connection : *connections) {
                std::string commando = "\"go " + connection->instruction(current_room) + "\"";
                possibleCommands.push_back(commando);
            }
            //show all possible monsters
            std::vector<Monster *> *monsters = current_room->getMonsters();
            for (Monster *monster : *monsters) {
                std::string commando = "\"attack " + monster->getName() + "\"";
                possibleCommands.push_back(commando);
            }
            possibleCommands.push_back("\"exit\"");

            //print all this stuff
            for (std::string command: possibleCommands) {
                sout(command);
            }
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
                }
            }
    }
}

void Game::show(std::vector<std::string> *params) {
    switch (status) {
        case 1:
            inCombat();
            break;
        default:
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
