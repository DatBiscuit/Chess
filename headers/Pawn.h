#include "GamePiece.h"

#ifndef PAWN_H
#define PAWN_H

class Pawn: public GamePiece {

    public:
        Pawn(std::string playerName, int x, int y);
        virtual bool validMove(int x, int y, GamePiece* a);
        bool isMoveToTakePiece(int x, int y, GamePiece* a);
        virtual bool gamePieceInPath(int x, int y, GamePiece* a);
    private:
        bool hasMoved = false;

};

#endif //PAWN_H