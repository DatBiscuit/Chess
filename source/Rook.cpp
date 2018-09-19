#include "Rook.h"


Rook::Rook(std::string playerName, int x, int y)
    :GamePiece(playerName, x, y, "rook") {
}

bool Rook::validMove(int x, int y, GamePiece* a) {
    return false;
}