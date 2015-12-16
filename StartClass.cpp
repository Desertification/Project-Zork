//
// Created by alex on 11/21/15.
//

#include "StartClass.h"
#include "Lib.h"


startClass::startClass() {

    //integer to exit the game
    int exit = 0;

    CommandParser parser;
    Game game(&exit);

    //couple the commands with the method from the class Game it will execute
    parser.registerCommand("sayhello", &Game::sayHello);
    parser.registerCommand("saybye", &Game::sayBye);
    parser.registerCommand("go", &Game::go);
    parser.registerCommand("show", &Game::show);
    parser.registerCommand("exit", &Game::exit);
    parser.registerCommand("attack", &Game::attack);
    parser.registerCommand("search", &Game::search);
    parser.registerCommand("grab", &Game::grab);
    parser.registerCommand("leave", &Game::leave);

    parser.registerCommand("drop", &Game::drop);
    parser.registerCommand("consume", &Game::consume);
    parser.registerCommand("use", &Game::use);
    parser.registerCommand("swing", &Game::swing);
    parser.registerCommand("info", &Game::info);
    parser.registerCommand("equip", &Game::equip);




    while(exit == 0) {
        if(using_ncurses){
            if(game.getHero()){updatevaluesplayer(game.getHero());}
            game.showPossibleCommands();
        }
        //listen for commands that are linked to methods from the Game class
        parser.listen(&game);

    }
}