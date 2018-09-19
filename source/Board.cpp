#include <Board.h>
#include <iostream>

void Board::printBoard() {
    std::cout << topLetters;
    for(int i = 0; i < boardSize; i++) {
        printf("%d", i);
        printf("|");
        for(int j = 0; j < boardSize; j++) {
            std::cout << board[i][j].type;
        }
        printf("|\n");
    }
}

void Board::initBoard() {

    for(int i = 0; i < boardSize; i++) {
        board[i] = new Tile[8];
    }

    bool blackSpace = false;
    for(int i = 0; i < boardSize; i++) {
        for(int j = 0; j < boardSize; j++) {
            if(blackSpace) {
                Tile add(" X ");
                board[i][j] = add;
                blackSpace = false;
            } else {
                Tile add2("   ");
                board[i][j] = add2;
                blackSpace = true;
            }
        }
        blackSpace = !blackSpace;
    }
}