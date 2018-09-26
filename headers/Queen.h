#include "GamePiece.h"

#ifndef QUEEN_H
#define QUEEN_H

class Queen: public GamePiece {

    public:
        Queen(std::string playerName, int x, int y);
        virtual bool validMove(int x, int y, GamePiece* a);
        virtual bool gamePieceInPath(int x, int y, GamePiece* a);
};

#endif //QUEEN_H