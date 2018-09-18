#include "GamePiece.h"

#ifndef BISHOP_H
#define BISHOP_H

class Bishop: public GamePiece {

    public:
        Bishop(std::string playerName, int x, int y);
        int GamePiece::maxSpaceMove = 8;

};

#endif //BISHOP_H