#include <iostream>
#include "StartClass.h"
#include <ncurses.h>

using namespace std;


int main() {
    //let the game begin
    //startClass startClass;


    //variables to determen the size of each window
    int maxx,maxy,y_size_picture,x_size_picture,x_begin_command,y_size_command,x_size_command,y_begin_health,x_size_health,y_size_health;

    //terminal screens and windows
    WINDOW *parentwindow, *picturewindow, *commandwindow, *healthwindow;
    initscr();

    //asking the full size of the terminal window
    getmaxyx(stdscr,maxx,maxy);

    //creating windows
    parentwindow=newwin(maxx,maxy,0,0);

    y_size_picture=(maxy/5)*4;
    x_size_picture=(maxy/5)*4;
    picturewindow=derwin(parentwindow,x_size_picture,y_size_picture,0,0);
    box(picturewindow,0,0);

    x_begin_command=((maxx/5)*4)+1;
    y_size_command=(maxy/5)*4;
    x_size_command=maxx-x_size_picture-1;
    commandwindow=derwin(parentwindow,x_size_command,y_size_command,x_begin_command,0);
    box(commandwindow ,0,0);

    y_begin_health=((maxy/5)*4)+1;
    y_size_health=maxy-y_size_picture-1;
    x_size_health=maxx;
    healthwindow=derwin(parentwindow,x_size_health,y_size_health,0,y_begin_health);
    box(healthwindow,0,0);

    return 0;
}
