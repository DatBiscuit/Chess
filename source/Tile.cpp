#include <Tile.h>


Tile::Tile(std::string type) {
    this->type = type;
}

Tile::Tile() {

}

void Tile::setGamePiece(GamePiece* add) {
    this->assignedPiece = add;
}

void Tile::removeGamePiece() {
    this->assignedPiece = NULL;
}

Tile::~Tile() {
    delete this->assignedPiece;
}