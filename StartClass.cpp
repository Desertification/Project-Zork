//
// Created by alex on 11/21/15.
//

#include "StartClass.h"
#include <ncurses.h>
#include <iostream>
using namespace std;


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


    //creating windows
    int maxx, maxy, ybeginafbeelding, xbeginafbeelding, ybegincommando, xbegincommando,ygrooteafbeelding,xgrooteafbeelding,ygrootecommando,xgrootecommando,ybeginwaarde,xbeginwaarde,ygrootewaarde,xgrootewaarde,xbeginans,ybeginans,xgrooteans,ygrooteans;
    initscr();
    WINDOW  *parentwin, *commandowin,*waardewin,*answerwin;

    //lengte en breedte van het scherm opvragen en afdrukken
    getmaxyx(stdscr,maxx,maxy);
    parentwin=newwin(maxx,maxy,0,0);
    printw("maxy = %d \n",maxy);
    printw("maxx = %d \n",maxx);

    //venstertje voor antwoord
    ybeginans=0;
    xbeginans=0;
    xgrooteans=(maxx-10-1);
    ygrooteans=(maxy-20-1);
    answerwin=derwin(parentwin,xgrooteans,ygrooteans,xbeginans,ybeginans);
    box(answerwin,0,0);
    mvwprintw(answerwin,0,0,"1");
    mvwprintw(answerwin,0,ygrooteans-1,"1");
    mvwprintw(answerwin,xgrooteans-1,ygrooteans-1,"1");
    mvwprintw(answerwin,xgrooteans-1,0,"1");


    //venstertje voor keuze commando's
    ybegincommando = 0;
    xbegincommando = (maxx-10);
    ygrootecommando = (maxy-20-1);
    xgrootecommando = 10;
    commandowin=derwin(parentwin,xgrootecommando,ygrootecommando,xbegincommando,ybegincommando);
    box(commandowin,0,0);
    mvwprintw(commandowin,0,0,"2");
    mvwprintw(commandowin,0,ygrootecommando-1,"2");
    mvwprintw(commandowin,xgrootecommando-1,ygrootecommando-1,"2");
    mvwprintw(commandowin,xgrootecommando-1,0,"2");


    //venstertje voor waarden player
    ybeginwaarde = (maxy-20);
    xbeginwaarde = 0;
    ygrootewaarde = 20;
    xgrootewaarde = maxx;
    printw("ybeginwaarde = %d \n",ybeginwaarde);
    printw("xbeginwaarde = %d \n",xbeginwaarde);
    printw("ygrootewaarde = %d \n",ygrootewaarde);
    printw("xgrootewaarde = %d \n",xgrootewaarde);
    waardewin=derwin(parentwin,xgrootewaarde,ygrootewaarde,xbeginwaarde,ybeginwaarde);
    box(waardewin,0,0);
    mvwprintw(waardewin,0,0,"3");
    mvwprintw(waardewin,0,ygrootewaarde-1,"3");
    mvwprintw(waardewin,xgrootewaarde-1,ygrootewaarde-1,"3");
    mvwprintw(waardewin,xgrootewaarde-1,0,"3");


    //the game
    while(exit == 0) {
        refresh();
        wrefresh(answerwin);
        wrefresh(waardewin);
        //menu maken
        char list [5][7]={"one","two","three","four","five"};
        char item [7];
        int ch, i=0, width=7;

        // now print all the menu items and highlight the first one
        for( i=0; i<5; i++ ) {
            if( i == 0 )
                wattron( commandowin, A_STANDOUT ); // highlights the first item.
            else
                wattroff( commandowin, A_STANDOUT );
            sprintf(item, "%-7s",  list[i]);
            mvwprintw( commandowin, i+1, 2, "%s", item );
        }
        wrefresh(commandowin);// update the terminal screen

        i = 0;
        noecho(); // disable echoing of characters on the screen
        keypad( commandowin, TRUE ); // enable keyboard input for the window.
        curs_set( 0 ); // hide the default screen cursor.

        // get the input
        while(( ch = wgetch(commandowin)) != 'q'){

            // right pad with spaces to make the items appear with even width.
            sprintf(item, "%-7s",  list[i]);
            mvwprintw( commandowin, i+1, 2, "%s", item );
            // use a variable to increment or decrement the value based on the input.
            switch( ch ) {
                case KEY_UP:
                    i--;
                    i = ( i<0 ) ? 4 : i;
                    break;
                case KEY_DOWN:
                    i++;
                    i = ( i>4 ) ? 0 : i;
                    break;
            }
            // now highlight the next item in the list.
            wattron( commandowin, A_STANDOUT );

            sprintf(item, "%-7s",  list[i]);
            mvwprintw( commandowin, i+1, 2, "%s", item);
            wattroff( commandowin, A_STANDOUT );
        }



        //listen for commands that are linked to methods from the Game class
        parser.listen(&game);


    }

    endwin();
}