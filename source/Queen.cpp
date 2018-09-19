#include "Queen.h"


Queen::Queen(std::string playerName, int x, int y)
    :GamePiece(playerName, x, y, "Queen") {
}

bool Queen::validMove(int x, int y, GamePiece* a) {
    return false;
}