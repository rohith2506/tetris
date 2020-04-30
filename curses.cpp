#include <iostream>
#include <curses.h>
#include <unistd.h>
#include <vector>
#include <string>

#define DELAY 30000

using namespace std;

int main() {
    initscr();
    
    while(1) {
        int nh, nw;
        getmaxyx(stdscr, nh, nw);
        mvprintw(5, 10, "current screen position: %d, %d", nh, nw); 
        refresh();
    }
    
    endwin();
    return 0;
}
