#include <string>

#ifndef GAMEPIECE_H
#define GAMEPIECE_H

using namespace std;

class GamePiece {
    public:
        std::string player;
        std::string pieceName;
        int x,y;

        // virtual bool validMove(int x, int y) = 0;
        void setPosition(int x, int y);
        GamePiece();
        GamePiece(std::string playerName, int posX, int posY, std::string name);
        ~GamePiece();

};

#endif //GAMEPIECE_H