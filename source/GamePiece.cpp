#include "GamePiece.h"

void GamePiece::setPosition(int x, int y) {
    this->x = x;
    this->y = y;
}

GamePiece::GamePiece(std::string playerName, int posX, int posY, std::string name) {
    player = playerName;
    pieceName = name;
    setPosition(posX, posY);
}

GamePiece::GamePiece() {

}







