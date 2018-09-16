#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <GamePiece.h>
#include <Pawn.h>

using namespace std;

    const int boardSize = 8;
    std::vector<GamePiece*> playerWhite;
    std::vector<GamePiece*> playerBlack;

    void printBoard();
    void setBoard();

    int main(int argc, char* argv[]) {
        printBoard();
        setBoard();
        printf("%d \n", playerWhite.back()->x);
        printf("%d \n", playerWhite.back()->y);

        return 0;
    }

    void printBoard() {
        bool blackSpace = false;
        printf("   a  b  c  d  e  f  g  h \n");
        for(int i = 0; i < boardSize; i++) {
            printf("%d", i);
            printf("|");
            for(int j = 0; j < boardSize; j++) {
                if(blackSpace) {
                    printf(" X ");
                    blackSpace = false;
                } else {
                    printf("   ");
                    blackSpace = true;
                }
            }
            blackSpace = !blackSpace;
            printf("|\n");
        }
        

    }

    void setBoard() {
        //Create one white player pawn
        Pawn* testPawn = new Pawn("white", 6, 0);
        printf("TestPawn x position before vector: %d \n", testPawn->x);
        printf("TestPawn y position before vector: %d \n", testPawn->y);
        playerWhite.push_back(testPawn);
    }

