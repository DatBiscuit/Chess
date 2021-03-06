#include "GamePiece.h"

#ifndef ROOK_H
#define ROOK_H

class Rook: public GamePiece {

    public:
        Rook(std::string playerName, int x, int y);
        virtual bool validMove(int x, int y, GamePiece* a);
        virtual bool gamePieceInPath(int x, int y, GamePiece* a);
};

#endif //ROOK_H