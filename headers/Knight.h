#include "GamePiece.h"

#ifndef KNIGHT_H
#define KNIGHT_H

class Knight: public GamePiece {

    public:
        Knight(std::string playerName, int x, int y);
        int GamePiece::maxSpaceMove = 4;
};

#endif //KNIGHT_H