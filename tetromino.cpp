#include <vector>
#include <string>
#include <iostream>

using namespace std;

enum Rotation { LEFT, UP, RIGHT, DOWN };
const int BOARD_SIZE = 4;

/*
class TetrominoPiece {
    public:
        virtual void rotatePiece();
        virtual void clearPiece();
        virtual void rotatePiece(int angle);
        virtual vector<vector<char> > getPiece();
};
*/

class StraightPiece {
    private:
    char piece[BOARD_SIZE][BOARD_SIZE];

    public:
    StraightPiece() {
        int row = 1;
        for(int col=0; col<BOARD_SIZE; col++)
            piece[row][col] = 'A';
    }

    void clearPiece() {
        for(int row=0; row<BOARD_SIZE; row++) {
            for(int col=0; col<BOARD_SIZE; col++)
                piece[row][col] = ' ';
        }
    }

    void displayPiece() {
        for(int row=0; row<BOARD_SIZE; row++) {
            for(int col=0; col<BOARD_SIZE; col++) {
                cout << piece[row][col];
            }
            cout << endl;
        }
    }

    void rotatePiece(char direction) {
        clearPiece();
        if(direction == 'w') {
            int row = 1;
            for(int col=0; col<BOARD_SIZE; col++)
                piece[row][col] = 'A';
        } else if(direction == 'd') {
            int col = 2;
            for(int row=0; row<BOARD_SIZE; row++) 
                piece[row][col] = 'A';
        } else if(direction == 's') {
            int row = 2;
            for(int col=0; col<BOARD_SIZE; col++)
                piece[row][col] = 'A';
        } else if(direction == 'a') { 
            int col = 1;
            for(int row=0; row<BOARD_SIZE; row++)
                piece[row][col] = 'A';
        }
        displayPiece();
    }
};

int main() {
    StraightPiece s;
    while(true) {
        char direction;
        cin >> direction;
        s.rotatePiece(direction);
    }
    return 0;
}
