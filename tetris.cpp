#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include <curses.h>

using namespace std;

// Declare game constants here
int boardHeight = 30, boardWidth = 10;

// Helper function
template<class T>
void print2dVector(vector<vector<T> > &v) {
    string output = "";
    for(int i=0; i<v.size(); i++) {
        for(int j=0; j<v[i].size(); j++) {
            output = output + v[i][j];
        }
        output = output + "\n";
    }
    cout << output << "\r";
    cout.flush();
}

int main() {

    // Declare the game board here
    vector<vector<char> > tetrisGameBoard(boardHeight, vector<char>(boardWidth, ' '));
    
    // Initialize ncurses
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    // Create a sub window which we are gonna use
    WINDOW * win = newwin(100, 100, 10, 10);


    vector<char> alphabets = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};
    for(auto &alphabet: alphabets) {
        tetrisGameBoard[0][0] = alphabet;
        tetrisGameBoard[0][boardWidth-1] = alphabet;
        for(int i=1; i<tetrisGameBoard.size(); i++) {
            for(int j=0; j<tetrisGameBoard[i].size(); j++) {
                if(j == 0 || j == boardWidth - 1) tetrisGameBoard[i][j] = alphabet;
                if(i == boardHeight - 1) tetrisGameBoard[i][j] = alphabet;
            }
        }
        // print the board
        print2dVector<char>(tetrisGameBoard);
        this_thread::sleep_for(chrono::milliseconds(50));
    }


    endwin();
    return  0;
}
