#include "GamePiece.h"

#ifndef PAWN_H
#define PAWN_H

class Pawn: public GamePiece {

    public:
        Pawn(std::string playerName, int x, int y);

};

#endif //PAWN_H