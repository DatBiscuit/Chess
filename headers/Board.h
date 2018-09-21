#include <Tile.h>

#ifndef BOARD_H
#define BOARD_H

class Board {
    public:
        void printBoard();
        void initBoard();
        void updateBoard(int oldX, int oldY, int newX, int newY);
        bool gamepieceAtSpot(int x, int y);

    private:
        Tile** board = new Tile*[8];
        const std::string topLetters = "   a  b  c  d  e  f  g  h \n";
        const int boardSize = 8;
        const int pawnSize = 8;
        void createPawns();
        void createKings();
        void createRooks();
        void createKnights();
        void createQueens();
        void createBishops();
        void printCorrespondingPiece(GamePiece* piece);

};

#endif //BOARD_H