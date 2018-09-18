#include "GamePiece.h"

#ifndef ROOK_H
#define ROOK_H

class Rook: public GamePiece {

    public:
        Rook(std::string playerName, int x, int y);
        int GamePiece::maxSpaceMove = 8;
};

#endif //ROOK_H