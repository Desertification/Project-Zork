//
// Created by alex on 11/21/15.
//

#include "StartClass.h"


startClass::startClass() {

    //integer to exit the game
    int exit = 0;

    CommandParser parser;
    Game game(&exit);

    //acouple the commands with the method from the class Game it will execute
    parser.registerCommand("sayhello", &Game::sayHello);
    parser.registerCommand("saybye", &Game::sayBye);
    parser.registerCommand("go", &Game::go);
    parser.registerCommand("show", &Game::show);
    parser.registerCommand("exit", &Game::exit);
    parser.registerCommand("attack", &Game::attack);




    while(exit == 0) {
        //listen for commands that are linked to methods from the Game class
        parser.listen(&game);
    }
}