#include <Tile.h>

#ifndef BOARD_H
#define BOARD_H

class Board {
    public:
        void printBoard();
        void initBoard();

    private:
        Tile** board = new Tile*[8];
        const std::string topLetters = "   a  b  c  d  e  f  g  h \n";
        const int boardSize = 8;
        const int pawnSize = 8;

};

#endif //BOARD_H