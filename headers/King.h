#include "GamePiece.h"

#ifndef KING_H
#define KING_H

class King: public GamePiece {

    public:
        King(std::string playerName, int x, int y);
        virtual bool validMove(int x, int y, GamePiece* a);
        virtual bool gamePieceInPath(int x, int y, GamePiece* a);
};

#endif //KING_H