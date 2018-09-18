#include "GamePiece.h"

#ifndef KING_H
#define KING_H

class King: public GamePiece {

    public:
        King(std::string playerName, int x, int y);
        int GamePiece::maxSpaceMove = 1;
};

#endif //KING_H