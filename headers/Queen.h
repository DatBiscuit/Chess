#include "GamePiece.h"

#ifndef QUEEN_H
#define QUEEN_H

class Queen: public GamePiece {

    public:
        Queen(std::string playerName, int x, int y);
        int GamePiece::maxSpaceMove = 8;
};

#endif //QUEEN_H