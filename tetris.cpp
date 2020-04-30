#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include <curses.h>

using namespace std;

// Declare game constants here
int boardHeight = 30, boardWidth = 30, heightGap = 5, widthGap = 12;

// Initialize the board and tetromnio pieces
vector<vector<char> > tetrisGameBoard(boardHeight, vector<char>(boardWidth, ' '));
vector<string> tetrominoPieces;

// Declare header position
int headerPositionY, headerPositionX;

// Declare tetris board start positions
int boardStartPositionX, boardStartPositionY;

// screen width
int nScreenHeight, nScreenWidth;


// check the board constraints
bool doesBoardFit() {
    // setup the position of the header
    headerPositionY = nScreenHeight / 5;
    headerPositionX = nScreenWidth / 2;

    // setup start position of board
    
    // set height
    if(headerPositionY + boardHeight + heightGap < nScreenHeight) 
        boardStartPositionY = headerPositionY + heightGap;
    else
        return false;

    // set width
    if(headerPositionX + boardWidth - widthGap >= 0 && headerPositionX + boardWidth - widthGap < nScreenWidth) 
        boardStartPositionX = headerPositionX - widthGap;
    else
        return false;

    return true;
}

void createBoard() {
    tetrisGameBoard[0][0] = 'X';
    tetrisGameBoard[0][boardWidth-1] = 'X';
    for(int i=1; i<tetrisGameBoard.size(); i++) {
        for(int j=0; j<tetrisGameBoard[i].size(); j++) {
            if(j == 0 || j == boardWidth - 1) tetrisGameBoard[i][j] = 'X';
            if(i == boardHeight - 1) tetrisGameBoard[i][j] = 'X';
        }
    }
}


//
void createTetrominoPieces() {
    vector<string> straightPiece = { "AAAA", "----", "----", "----" };
    vector<string> LPiece = { "A---", "AAA-", "----", "----" };
    vector<string> invertedLPiece = { "---A", "-AAA", "----", "----" };
    vector<string> squarePiece;

    tetrominoPieces.push_back(straightPiece);
}

int main() { 
    // Initialize ncurses
    initscr();
    // create the board
    createBoard();
    // create tetromino pieces
    createTetrominoPieces();

    int ch;
    while(1) {
        getmaxyx(stdscr, nScreenHeight, nScreenWidth);
        clear();
        if(!doesBoardFit()) {
            printw("Board don't fit into the terminal");
            refresh();
            this_thread::sleep_for(chrono::milliseconds(1000));
            break;
        }

        // print the header
        mvprintw(headerPositionY, headerPositionX, "TETRIS");
    
        // print the board
        printGame(tetrisGameBoard, tetrominoPieces);
        
        // finally print the content
        refresh();

        this_thread::sleep_for(chrono::milliseconds(50));
    }

    // End the window screen
    endwin();
    
    return  0;
}
