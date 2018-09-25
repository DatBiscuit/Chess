#include "Knight.h"


Knight::Knight(std::string playerName, int x, int y)
    :GamePiece(playerName, x, y, "knight") {
}

bool Knight::validMove(int x, int y, GamePiece* a) {
    if(abs(a->x - x) == 1) {
        if(abs(a->y - y) == 2) {
            return true;
        }
    }
    if(abs(a->x - x) == 2) {
        if(abs(a->y - y) == 1) {
            return true;
        }
    }
    return false;
}