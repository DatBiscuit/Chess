#include <string>

#ifndef GAMEPIECE_H
#define GAMEPIECE_H

using namespace std;

class GamePiece {
    public:
        std::string player;
        std::string pieceName;
        int x,y;
        int maxSpaceMove;

        virtual bool validMove(int x, int y, GamePiece* a);
        void setPosition(int x, int y);
        GamePiece();
        GamePiece(std::string playerName, int posX, int posY, std::string name);

        bool getHasMoved();
        void setHasMoved();

    private:
        bool hasMoved = false;
};

#endif //GAMEPIECE_H