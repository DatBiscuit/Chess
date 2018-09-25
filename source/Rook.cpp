#include "Rook.h"


Rook::Rook(std::string playerName, int x, int y)
    :GamePiece(playerName, x, y, "rook") {
}

bool Rook::validMove(int x, int y, GamePiece* a) {

    if(a->y != y && a->x != x) {
        return false;
    }
    
    return true;
}