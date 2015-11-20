//
// Created by alex on 11/20/15.
//

#ifndef GAMETEST_GAME_H
#define GAMETEST_GAME_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

class Game {

public:
    void sayHello(std::vector<std::string> * params);
    void sayBye(std::vector<std::string> * params);
    void go(std::vector<std::string> * params);


};


// Make type of command function pointer
typedef void (Game::*commandPointer)(std::vector<std::string> *);


#endif //GAMETEST_GAME_H
