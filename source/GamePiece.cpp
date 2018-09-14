#include <string>

using namespace std;

class GamePiece {
    public:
        std::string player;
        std::string pieceName;
        int x,y;
        bool outOfPlay;

        virtual bool validMove(int x, int y) = 0;
};