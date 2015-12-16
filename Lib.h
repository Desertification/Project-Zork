//
// Created by thomas on 12/9/15.
//

// Dump

#ifndef GAMETEST_MYLIB_H
#define GAMETEST_MYLIB_H

#include <string>
#include <ncurses.h>
#include <vector>
#include <algorithm>

extern bool using_ncurses;
extern WINDOW *parentwin;
extern WINDOW *answerwin;
extern WINDOW *commandwin;
extern WINDOW *valuewin;
extern std::vector<std::string> *menu;
extern std::string line;

//window refreshen
void refreshwindow(WINDOW* win);

//windows creeëren
void createwindows();

//functie om in answerwindow te printen
void printanswerwindow();

//to print on terminal or on window
void println(std::string text);

//get possibelcommands
void setpossiblecommands(std::vector<std::string> possiblecommands);

std::string getLine();


#endif //GAMETEST_MYLIB_H
