//
// Created by alex on 10/31/15.
//

#include "CommandInterpreter.h"

//TODO: refractor with a better command parser (https://github.com/BioBoost/cpp_creeps_command_parser)
CommandInterpreter::CommandInterpreter(Room *current_room, int *exit, Hero *hero) {
    this->current_room = current_room;
    this->exit = exit;
    this->hero = hero;
}

void CommandInterpreter::interpretInput(std::string input) {
    //split the string
    std::vector<std::string> stringVector = split(input, ' ');

    //to exit the application, both the first and last word need to be exit, to allow for later implementation of
    //something like "exit dungeon"
    if (stringVector.front() == "exit") {
        if (stringVector.back() == "exit") {
            *exit = 1;
        }
    }

        //if the command is go
    else if (stringVector.front() == "go") {
        //if the room isn't recognized
        if (current_room->go(stringVector.back()) == NULL) {
            sout("No such room aviable");
        } else {
            //if the room is recognized, go to the new room, and explore it
            current_room = current_room->go(stringVector.back());
            std::cout << current_room->explore();
        }
    }

        //if the command is get
    else if (stringVector.front() == "show") {
        //return all available commands
        if (stringVector.back() == "commands") {
            std::vector<std::string> possibleCommands = getPossibleCommands();
            for (std::string command: possibleCommands) {
                sout(command);
            }
        }

            //show a random number, going to let this in the code as a kind of easter egg
        else if (stringVector.back() == "random") {
            std::random_device *randomDevice = new std::random_device();
            std::cout << randomDevice->operator()() << std::endl;
            std::cout << randomDevice->operator()() % 100 << std::endl; //between 0 and 100
            delete randomDevice;
        }
        else {
            sout("No such command");
        }
    }

        //if the command is attack
    else if (stringVector.front() == "attack") {
        //get all the monsters in the current room
        std::vector<Monster *> *monsters = current_room->getMonsters();
        //check if the monster is in the room
        unsigned int contains = 0;
        Monster *combatMoster;
        for (Monster *monster : *monsters) {
            if (monster->getName() == stringVector.back()) {
                combatMoster = monster;
                contains = 1;
            }
        }
        if (contains == 1) {
            int inCombat = true;
            sout("you are now in combat");
            do {
                sout(std::string("fast attack (damage :") +
                     std::to_string(hero->getDamage() - combatMoster->getArmor()) + " chance to hit : " +
                     std::to_string(
                             100 - combatMoster->getChanceToDodge(hero->getQuickness())) + " %)");
                sout("INSERT: \"fast attack\" for a normal attack");
                sout(std::string("strong attack (damage :") +
                     std::to_string(hero->getDamage() * 2 - combatMoster->getArmor()) + " chance to hit : " +
                     std::to_string(
                             100 - combatMoster->getChanceToDodge(hero->getQuickness() / 2)) + " %)");
                sout("INSERT: \"strong attack\" for a strong attack");
                sout("the enemy has " + std::to_string(combatMoster->getHealth()) + " hp");
                sout("You have " + std::to_string(hero->getHealth()) + " hp");

                //managing the input
                int mistake = false;
                do {
                    std::string command;
                    getline(std::cin, command);
                    std::vector<std::string> stringAttackVector = split(command, ' ');

                    if (stringAttackVector.front() == "fast" && stringAttackVector[1] == "attack") {
                        mistake = false;
                        int damageGiven = combatMoster->takeDamage(hero->getDamage(), hero->getQuickness());
                        inCombat = damageGivenMethod(combatMoster, damageGiven);
                    }

                    else if (stringAttackVector.front() == "strong" && stringAttackVector[1] == "attack") {
                        mistake = false;
                        int damageGiven = combatMoster->takeDamage(hero->getDamage() * 2, hero->getQuickness() / 2);
                        inCombat = damageGivenMethod(combatMoster, damageGiven);
                    }
                    else {
                        mistake = true;
                        sout("invalid input");
                    }
                } while (mistake);


                //now the monsters turn to attack, just in case


            } while (inCombat);
            sout("You have triumphed over your enemies");
        }
        else {
            sout("no such monster in this room");
        }
    }

    else {
        sout("No such command");
    }
}

int CommandInterpreter::damageGivenMethod(Monster *combatMoster, int damageGiven) {
    if (damageGiven == -1) {
        sout(combatMoster->getName() + " dodged your attack");
        return true;
    } else {
        sout("you dealt " + std::to_string(damageGiven) + " to " + combatMoster->getName());
        if (combatMoster->getHealth() <= 0) {
            return false;
        }else{
            return true;
        }
    }
}

void CommandInterpreter::sout(std::string message) {
    std::cout << message << std::endl;
}

std::vector<std::string> CommandInterpreter::getPossibleCommands() {
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
    return possibleCommands;
}

//split the string
std::vector<std::string> CommandInterpreter::split(const std::string &text, char sep) {
    std::vector<std::string> tokens;
    int start = 0, end = 0;
    while ((end = text.find(sep, start)) != std::string::npos) {
        tokens.push_back(text.substr(start, end - start));
        start = end + 1;
    }
    tokens.push_back(text.substr(start));
    return tokens;
}
