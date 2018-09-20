#include "Pawn.h"


Pawn::Pawn(std::string playerName, int x, int y)
    :GamePiece(playerName, x, y, "pawn") {
}

bool Pawn::validMove(int x, int y, GamePiece* a) {
    //Can only move up 2 on first move or up one
    //Only considered black's move
    if(a->player.compare("black") == 0) {
        if(a->y != y) {
            return false;
        }
        if(a->x + 2 == y) {
           
            return true;
        } else {
            if(a->x + 1 == y) {
                return true;
            }
            return false;
        }
    } else { //must be the white player
        if(a->y != y) {
            return false;
        }
        if(a->x - 2 == y) {
        
            return true;
        } else {
            if(a->x - 1 == y) {
                return true;
            }
            return false;
        }
    }

    return false;
}
