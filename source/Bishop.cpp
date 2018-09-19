#include "Bishop.h"


Bishop::Bishop(std::string playerName, int x, int y)
    :GamePiece(playerName, x, y, "bishop") {
}

bool Bishop::validMove(int x, int y, GamePiece* a) {
    return false;
}