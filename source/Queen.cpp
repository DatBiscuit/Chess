#include "Queen.h"


Queen::Queen(std::string playerName, int x, int y)
    :GamePiece(playerName, x, y, "queen") {
}

bool Queen::validMove(int x, int y, GamePiece* a) {
    if(abs(a->x - x) == abs(a->y - y)) {
        return true;
    }
    if(a->y == y || a->x == x) {
        return true;
    }
    return false;
}