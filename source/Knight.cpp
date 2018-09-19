#include "Knight.h"


Knight::Knight(std::string playerName, int x, int y)
    :GamePiece(playerName, x, y, "knight") {
}

bool Knight::validMove(int x, int y, GamePiece* a) {
    return false;
}