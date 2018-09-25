#include "King.h"
#include <cmath>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>


King::King(std::string playerName, int x, int y)
    :GamePiece(playerName, x, y, "king") {
}

bool King::validMove(int x, int y, GamePiece* a) {
    if(abs(a->x - x) == abs(a->y - y)) {
        if(abs(a->x - x) == 1) {
            return true;
        }
    }
    if(abs(a->x - x) == 1 && abs(a->y - y) == 0) {
        return true;
    }
    if(abs(a->x - x) == 0 && abs(a->y - y) == 1) {
        return true;
    }

    return false;
}