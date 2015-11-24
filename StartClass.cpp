//
// Created by alex on 11/21/15.
//

#include "StartClass.h"


startClass::startClass() {
    CommandParser parser;
    Game game;

    game.init();

    //add the commands
    parser.registerCommand("sayhello", &Game::sayHello);
    parser.registerCommand("saybye", &Game::sayBye);
    parser.registerCommand("go", &Game::go);

    //integer to exit the game
    int exit = 0;

    while(exit == 0) {
        //listen for context
        parser.listen(&game);
    }
}