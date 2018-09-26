#include "Pawn.h"
#include <cmath>


Pawn::Pawn(std::string playerName, int x, int y)
    :GamePiece(playerName, x, y, "pawn") {
}

bool Pawn::validMove(int x, int y, GamePiece* a) {
    if(a->player.compare("black") == 0) {
        if(a->y != y) {
            return false;
        }
        if(a->x - 2 == x && !hasMoved) {
            hasMoved = true;
            return true;
        } else {
            if(a->x - 1 == x) {
                hasMoved = true;
                return true;
            }
            return false;
        }
    } else { //must be the white player
        if(a->y != y) {
            return false;
        }
        if(a->x + 2 == x && !hasMoved) {
            hasMoved = true;
            return true;
        } else {
            if(a->x + 1 == x) {
                hasMoved = true;
                return true;
            }
            return false;
        }
    }
}

bool Pawn::isMoveToTakePiece(int x, int y, GamePiece* a) {
    if(a->player.compare("black")) {
        if(a->x - 1 == x && abs(a->y - y) == 1) {
            return true;
        }

    } else { //must be the white player
        if(a->x + 1 == x && abs(a->y - y) == 1) {
            return true;
        }
        return false;
    }

    return false;
}
