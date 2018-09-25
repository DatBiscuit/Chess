#include "Bishop.h"
#include <cmath>


Bishop::Bishop(std::string playerName, int x, int y)
    :GamePiece(playerName, x, y, "bishop") {
}

bool Bishop::validMove(int x, int y, GamePiece* a) {
    if(abs(a->x - x) == abs(a->y - y)) {
        return true;
    }
    return false;
}