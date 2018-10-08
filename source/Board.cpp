#include <Board.h>
#include <iostream>

void Board::printBoard() {
    std::cout << topLetters;
    for(int i = 0; i < boardSize; i++) {
        printf("%d", i);
        printf("|");
        for(int j = 0; j < boardSize; j++) {
            if(board[i][j].assignedPiece != NULL) {
                std::cout << " ";
                if(board[i][j].assignedPiece->player.compare("white")) {
                    std::cout << "w";
                } else {
                    std::cout << "b";
                }
                printCorrespondingPiece(board[i][j].assignedPiece);
            } else {
                std::cout << board[i][j].type;
            }
        }
        printf("|\n");
    }
}

void Board::printCorrespondingPiece(GamePiece* piece) {
    if(piece->pieceName.compare("pawn") == 0) {
        std::cout << "p";
    }
    if(piece->pieceName.compare("rook") == 0) {
        std::cout << "r";
    }
    if(piece->pieceName.compare("bishop") == 0) {
        std::cout << "b";
    }
    if(piece->pieceName.compare("knight") == 0) {
        std::cout << "k";
    }
    if(piece->pieceName.compare("king") == 0) {
        std::cout << "K";
    }
    if(piece->pieceName.compare("queen") == 0) {
        std::cout << "Q";
    }

}

void Board::initBoard() {

    for(int i = 0; i < boardSize; i++) {
        board[i] = new Tile[8];
    }

    bool blackSpace = false;
    for(int i = 0; i < boardSize; i++) {
        for(int j = 0; j < boardSize; j++) {
            if(blackSpace) {
                Tile add(" X ");
                board[i][j] = add;
                blackSpace = false;
            } else {
                Tile add2("   ");
                board[i][j] = add2;
                blackSpace = true;
            }
        }
        blackSpace = !blackSpace;
    }

    createPawns();
    createBishops();
    createKings();
    createKnights();
    createQueens();
    createRooks();
}

void Board::createPawns() {
    for(int i = 0; i < pawnSize; i++) {
        Pawn* addwhite = new Pawn("white", 1, i);
        board[1][i].assignedPiece = addwhite;
        Pawn* addblack = new Pawn("black", 6, i);
        board[6][i].assignedPiece = addblack;
    }

}

void Board::createRooks() {
    Rook* addwhite = new Rook("white", 0, 0);
    board[0][0].assignedPiece = addwhite;
    Rook* addwhite1 = new Rook("white", 0, 7);
    board[0][7].assignedPiece = addwhite1;

    Rook* addblack = new Rook("black", 7, 0);
    board[7][0].assignedPiece = addblack;
    Rook* addblack1 = new Rook("black", 7, 7);
    board[7][7].assignedPiece = addblack1;
}

void Board::createKnights() {
    Knight* addwhite = new Knight("white", 0, 1);
    board[0][1].assignedPiece = addwhite;
    Knight* addwhite1 = new Knight("white", 0, 6);
    board[0][6].assignedPiece = addwhite1;

    Knight* addblack = new Knight("black", 7, 1);
    board[7][1].assignedPiece = addblack;
    Knight* addblack1 = new Knight("black", 7, 6);
    board[7][6].assignedPiece = addblack1;
}

void Board::createBishops() {
    Bishop* addwhite = new Bishop("white", 0, 2);
    board[0][2].assignedPiece = addwhite;
    Bishop* addwhite1 = new Bishop("white", 0, 5);
    board[0][5].assignedPiece = addwhite1;

    Bishop* addblack = new Bishop("black", 7, 2);
    board[7][2].assignedPiece = addblack;
    Bishop* addblack1 = new Bishop("black", 7, 5);
    board[7][5].assignedPiece = addblack1;
}

void Board::createQueens() {
    Queen* addwhite = new Queen("white", 0, 4);
    board[0][4].assignedPiece = addwhite;

    Queen* addblack = new Queen("black", 7, 4);
    board[7][4].assignedPiece = addblack;

}

void Board::createKings() {
    King* addwhite = new King("white", 0, 3);
    board[0][3].assignedPiece = addwhite;

    King* addblack = new King("black", 7, 3);
    board[7][3].assignedPiece = addblack;

}

bool Board::updateBoard(int oldX, int oldY, int newX, int newY) {
    if(oldX == newX && oldY == newY) {
        return false;
    }
    GamePiece* movedPiece = board[oldX][oldY].assignedPiece;

    if(!movedPiece->validMove(newX, newY, movedPiece)) {
        //Checking the pawn's second valid move, only special piece to takeover pieces
        if(movedPiece->pieceName.compare("pawn")) {
            Pawn* pawn = NULL;
            if(pawn->isMoveToTakePiece(newX, newY, movedPiece) && gamepieceAtSpot(newX, newY)) {
                movePiece(movedPiece, newX, newY);
                return true;
            }
        } else {
            return false;
        }
    }

    if(isThereAPieceInTheWay(movedPiece, newX, newY)) {
        return false;
    }

    if(gamepieceAtSpot(newX, newY) && isTakingOverPiece(newX, newY, movedPiece)) {
        movePiece(movedPiece, newX, newY);
        return true;
    }

    movePiece(movedPiece,newX,newY);
    return true;
}

bool Board::gamepieceAtSpot(int x, int y) {
    if(board[x][y].assignedPiece == NULL) {
        return false;
    }
    return true;
}

bool Board::rightColorPiece(bool whitesTurn, int x, int y) {
    if(whitesTurn && board[x][y].assignedPiece->player.compare("white")) {
        return true;
    }
    if(!whitesTurn && board[x][y].assignedPiece->player.compare("black")) {
        return true;
    }
    return false;
}

void Board::movePiece(GamePiece* movedPiece, int newX, int newY) {
    board[movedPiece->x][movedPiece->y].assignedPiece = NULL;
    movedPiece->setPosition(newX, newY);
    board[newX][newY].assignedPiece = movedPiece;
}

bool Board::isTakingOverPiece(int newX, int newY, GamePiece* movingPiece) {
    GamePiece* old = board[newX][newY].assignedPiece;
    if(!old->player.compare(movingPiece->player)) {
        board[newX][newY].assignedPiece = NULL;
        delete old;
        return true;
    }
    return false;
}

bool Board::isThereAPieceInTheWay(GamePiece* movingPiece, int newX, int newY) {
    //is it a knight
    if(movingPiece->pieceName.compare("knight")) {
        return false;
    }

    //is it moving one space
    if(movingPiece->x == newX) {
        if(abs(movingPiece->y - newY) == 1) {
            return false;
        }
    }
    if(movingPiece->y == newY) {
        if(abs(movingPiece->x - newX) == 1) {
            return false;
        }
    }
    if(abs(movingPiece->x - newX) == 1 && abs(movingPiece->y - newY) == 1) {
        return false;
    }

    //is it moving up or down
    if(movingPiece->y == newY) {
        if(movingPiece->x > newX) {
            for(int i = movingPiece->x; i > newX; i--) {
                if(gamepieceAtSpot(i, newY)) {
                    return true;
                }
            }
            return false;
        } else {
            for(int i = movingPiece->x; i < newX; i++) {
                if(gamepieceAtSpot(i, newY)) {
                    return true;
                }
            }
            return false;
        }
    }
    
    //is it moving left or right
    if(movingPiece->x == newX) {
        if(movingPiece->y > newY) {
            for(int i = movingPiece->y; i > newY; i--) {
                if(gamepieceAtSpot(newX, i)) {
                    return true;
                }
            }
            return false;
        } else {
            for(int i = movingPiece->y; i < newY; i++) {
                if(gamepieceAtSpot(newX, i)) {
                    return true;
                }
            }
            return false;
        }

    }

    //is it moving diagonal 4 conditions: x+y+, x-y-, x+y-, x-y+
    if(movingPiece->x > newX && movingPiece->y > newY) {
        int x = movingPiece->x - 1;
        int y = movingPiece->y - 1;
        while(x > newX && y > newY) {
            if(gamepieceAtSpot(x, y)) {
                return true;
            }
            x--;
            y--;
        }
    }

    if(movingPiece->x < newX && movingPiece->y < newY) {
        int x = movingPiece->x + 1;
        int y = movingPiece->y + 1;
        while(x < newX && y < newY) {
            if(gamepieceAtSpot(x, y)) {
                return true;
            }
            x++;
            y++;
        }
    }

    if(movingPiece->x > newX && movingPiece->y < newY) {
        int x = movingPiece->x - 1;
        int y = movingPiece->y + 1;
        while(x > newX && y < newY) {
            if(gamepieceAtSpot(x, y)) {
                return true;
            }
            x--;
            y++;
        }
    }

    if(movingPiece->x < newX && movingPiece->y > newY) {
        int x = movingPiece->x + 1;
        int y = movingPiece->y - 1;
        while(x < newX && y > newY) {
            if(gamepieceAtSpot(x, y)) {
                return true;
            }
            x++;
            y--;
        }
    }
    
    return false;
}


