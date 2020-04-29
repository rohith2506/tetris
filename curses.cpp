#include <iostream>
#include <curses.h>
#include <unistd.h>
#include <vector>
#include <string>

#define DELAY 30000

using namespace std;

void func(WINDOW *window, vector<string> arr) {
    for (int i = 0; i < arr.size(); i++) {
        for(int j=0; j < arr[i].size(); j++) {
            waddch(window, arr[i][j]);
        }
    }
}

int main() {
    initscr();
    noecho();
    curs_set(FALSE);
    WINDOW * win = newwin(100, 100, 10, 10);
    vector<string> arr = {"hello", "bye"};
    while(1) {
        clear();
        func(win, arr);
        refresh();
        usleep(DELAY);
    }
    endwin();
    return 0;
}
