//
// Created by alex on 11/20/15.
//

#include "Game.h"


void Game::sayHello(std::vector<std::string> * params) {
    std::cout << "Dude ... HELLLLLLOOOOO ......" << std::endl;
}

void Game::sayBye(std::vector<std::string> * params) {
    std::cout << "Dude ... BE GONEEEEE ......" << std::endl;
}

void Game::go(std::vector<std::string> * params) {
    if (params->size() >= 1) {
        std::cout << "Going to room " << (*params)[0] << std::endl;
    }
}