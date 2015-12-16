//
// Created by thomas on 12/9/15.
//

#include "Lib.h"
#include "Living_Things/entity.h"
#include <iostream>

bool using_ncurses=true;
WINDOW *parentwin = nullptr;
WINDOW *answerwin = nullptr;
WINDOW *commandwin = nullptr;
WINDOW *valuewin = nullptr;
std::vector<std::string> *menu = new std::vector<std::string>;
std::string line = "";

void refreshwindow(WINDOW *win) {
    wrefresh(win);

}

void createwindows() {
    if (using_ncurses){
        initscr();
        int maxx, maxy;
        int ybegincommand, xbegincommand, ygrootecommand, xgrootecommand;
        int ybeginvalue, xbeginvalue, ygrootevalue, xgrootevalue;
        int xbeginans, ybeginans, ygrooteans, xgrooteans;

        //lengte en breedte van het scherm opvragen en afdrukken
        getmaxyx(stdscr, maxx, maxy);
        parentwin = newwin(maxx, maxy, 0, 0);
        printw("maxy = %d \n", maxy);
        printw("maxx = %d \n", maxx);

        //venstertje voor antwoord
        ybeginans = 0;
        xbeginans = 0;
        xgrooteans = (maxx - 10 - 1);
        ygrooteans = (maxy - 20 - 1);
        answerwin = derwin(parentwin, xgrooteans, ygrooteans, xbeginans, ybeginans);

        //venstertje voor keuze commando's
        ybegincommand = 0;
        xbegincommand = (maxx - 10);
        ygrootecommand = (maxy - 20 - 1);
        xgrootecommand = 10;
        commandwin = derwin(parentwin, xgrootecommand, ygrootecommand, xbegincommand, ybegincommand);
        box(commandwin, 0, 0);

        //venstertje voor waarden player
        ybeginvalue = (maxy - 20);
        xbeginvalue = 0;
        ygrootevalue = 20;
        xgrootevalue = maxx;
        valuewin = derwin(parentwin, xgrootevalue, ygrootevalue, xbeginvalue, ybeginvalue);

        refresh();
        wrefresh(answerwin);
        wrefresh(commandwin);
        wrefresh(valuewin);
    }
}

void println(std::string text) {
    if(using_ncurses) {
        werase(answerwin);
        mvwprintw(answerwin,0,0,text.c_str());
        wrefresh(answerwin);
    }

    else{
        std::cout << text + "\n";
    }
}



void setpossiblecommands(std::vector<std::string> possibleCommands) {

    if(using_ncurses) {
        menu->clear();
        for (std::string command: possibleCommands) {
            menu->push_back(command);
        }

        //menu maken
        int ch, i = 0, width = 7;

        // now print all the menu items and highlight the first one
        werase(commandwin);
        box(commandwin, 0, 0);
        for (i = 0; i < menu->size(); i++) {
            if (i == 0)
                wattron(commandwin, A_STANDOUT); // highlights the first item.
            else
                wattroff(commandwin, A_STANDOUT);
            mvwprintw(commandwin, i + 1, 2, menu->at(i).c_str());
        }
        wrefresh(commandwin);// update the terminal screen

        i = 0;
        noecho(); // disable echoing of characters on the screen
        keypad(commandwin, TRUE); // enable keyboard input for the window.
        curs_set(0); // hide the default screen cursor.


        // get the input
        while ((ch = wgetch(commandwin)) != 10) {

            // right pad with spaces to make the items appear with even width.
            mvwprintw(commandwin, i + 1, 2, menu->at(i).c_str());
            // use a variable to increment or decrement the value based on the input.
            switch (ch) {
                case KEY_UP:
                    i--;
                    i = (i < 0) ? menu->size() - 1 : i;
                    break;
                case KEY_DOWN:
                    i++;
                    i = (i > menu->size() - 1) ? 0 : i;
                    break;
            }
            // now highlight the next item in the list.
            wattron(commandwin, A_STANDOUT);
            mvwprintw(commandwin, i + 1, 2, menu->at(i).c_str());
            wattroff(commandwin, A_STANDOUT);
        }
        line = (std::string) menu->at(i).c_str();
    }else{
        for (std::string command: possibleCommands) {
            println(command);
        }
    }
}

std::string getLine() {
    line.erase(std::remove(line.begin(),line.end(),'\"'),line.end());
    return line;
}


void updatevaluesplayer(Entity *hero) {

    werase(valuewin);
    mvwprintw(valuewin,0,0,"The Player:");
    mvwprintw(valuewin,1,0,"-------------");
    mvwprintw(valuewin,3,0,"Name:");
    mvwprintw(valuewin,4,0,hero->getName().c_str());
    mvwprintw(valuewin,6,0,"Health:");
    mvwprintw(valuewin,7,0, std::to_string(hero->getHealth()).c_str());
    mvwprintw(valuewin,9,0,"Stamina:");
    mvwprintw(valuewin,10,0, std::to_string(hero->getStamina()).c_str());
    mvwprintw(valuewin,12,0,"Damage:");
    mvwprintw(valuewin,13,0, std::to_string(hero->getDamage()).c_str());
    mvwprintw(valuewin,15,0,"Item:");
    if(hero->getItem()) {
        mvwprintw(valuewin, 16, 0, hero->getItem()->getName().c_str());
    }else{
        mvwprintw(valuewin,16,0,"No Item");
    }
    wrefresh(valuewin);




}
