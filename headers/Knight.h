#include "GamePiece.h"

#ifndef KNIGHT_H
#define KNIGHT_H

class Knight: public GamePiece {

    public:
        Knight(std::string playerName, int x, int y);
        bool validMove(int x, int y, GamePiece* a);
};

#endif //KNIGHT_H