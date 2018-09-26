#include "GamePiece.h"

#ifndef BISHOP_H
#define BISHOP_H

class Bishop: public GamePiece {

    public:
        Bishop(std::string playerName, int x, int y);
        virtual bool validMove(int x, int y, GamePiece* a);
        virtual bool gamePieceInPath(int x, int y, GamePiece* a);

};

#endif //BISHOP_H