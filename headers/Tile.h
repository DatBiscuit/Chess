#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <GamePiece.h>
#include <Pawn.h>
#include <Bishop.h>
#include <Queen.h>
#include <Rook.h>
#include <Knight.h>
#include <King.h>



#ifndef TILE_H
#define TILE_H

using namespace std;

class Tile {
    public:
        Tile();
        ~Tile();
        Tile(std::string type);
        std::string type = "";
        GamePiece* assignedPiece = NULL;
        void setGamePiece(GamePiece* add);
        void removeGamePiece();

};

#endif //TILE_H