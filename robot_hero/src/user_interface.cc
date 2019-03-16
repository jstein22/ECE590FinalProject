#include <unistd.h>
#include <iostream>
#include <string>
#include "robot.h"


using namespace robot;


//bool drawn = false;

UserInterface::UserInterface(Robot& rob) : Process("user input"), _robot(rob) {
    initscr();   // Start ncurses
    timeout(1);  // Timeout for waiting for user input
    noecho();    // Do not echo user input to the screen
    curs_set(0); // Do not show the cursor
};


void UserInterface::show_robot(){
    //initscr();
    WINDOW *win = newwin(4,4,1,1);
    box(win, '|', '-');
    mvwin(win,4,13);   
    touchwin(win);
    wrefresh(win);
    //getchar();
    //endwin();

}

void UserInterface::update() {

    // USER INPUT
    // get a character from the user, if one is ready.
    // If no character is ready, getch() returns ERR (which is
    // ignored below since there is no condition in the switch statement)
    int c = getch();

    switch ( c ) {            
        case 'o':
            emit(Event("on"));
            break;
        case 'd':
            emit(Event("off"));
            clear(); // Clear the screen of old stuff
            break;
        case 's':
            emit(Event("start"));
            break;
        case 'q':
            std::cout << "halting\n";
            halt();
            break;
    }

    // OUTPUT
    show_robot();  
    mvprintw(10,1,"on(o), off(d), start(s), quit(q)");
    
    for ( int i=0; i<_robot.addEvents().size(); i++ ) {
        mvprintw(11+i, 1, "Event: %s", _robot.addEvents()[i].c_str());
    }

    // NOTE: Since the program is running every 10 ms, we should sleep
    //       the ui to give processing time back to the OS. It is debatable
    //       whether this is the right place to put this. It could also become
    //       an Elma feature, or it could go in the StopWatch class, etc.
    //       The number 9999 should also be a parameter and not a constant.
    usleep(9999);

}