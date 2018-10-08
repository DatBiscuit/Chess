#include <stdlib.h>
#include <stdio.h>
#include <string>


#ifndef GAMEPIECE_H
#define GAMEPIECE_H


class GamePiece {
    public:
        std::string player;
        std::string pieceName;
        int x,y;

        virtual bool validMove(int x, int y, GamePiece* a) = 0;
        void setPosition(int x, int y);
        GamePiece();
        GamePiece(std::string playerName, int posX, int posY, std::string name);

};

#endif //GAMEPIECE_H