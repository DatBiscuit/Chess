#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <list>
#include <algorithm>
#include <GamePiece.h>
#include <Pawn.h>
#include <Bishop.h>
#include <Queen.h>
#include <Rook.h>
#include <Knight.h>
#include <King.h>


using namespace std;

    const int pawnSize = 8;
    const int boardSize = 8;
    std::list<GamePiece*> playerWhite;
    std::list<GamePiece*> playerBlack;

    void printBoard();
    void setBoard();
    void createBishops();
    void createKings();
    void createPawns();
    void createQueens();
    void createRooks();
    void createKnights();

    int main(int argc, char* argv[]) {
        printBoard();
        setBoard();
        // printf("%d \n", playerWhite.back()->x);
        // printf("%d \n", playerWhite.back()->y);

        close();

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

        createPawns();
        createBishops();
        createKnights();
        createRooks();
        createQueens();
        createKings();

        // printf("TestPawn x position before vector: %d \n", testPawn->x);
        // printf("TestPawn y position before vector: %d \n", testPawn->y);
    }

    void createPawns() {
        for(int i = 0; i < pawnSize; i++) {
            Pawn* add = new Pawn("white", 6, i);
            playerWhite.push_back(add);
            Pawn* add2 = new Pawn("black", 1, i);
            playerBlack.push_back(add2);
        }
    }

    void createBishops() {
        //White's bishops
        Bishop* add = new Bishop("white", 7, 2);
        Bishop* add2 = new Bishop("white", 7, 5);
        playerWhite.push_back(add);
        playerWhite.push_back(add2);

        //Black's bishops
        Bishop* add3 = new Bishop("black", 0, 2);
        Bishop* add4 = new Bishop("black", 0, 5);
        playerBlack.push_back(add3);
        playerBlack.push_back(add4);
    }

    void createRooks() {
        Rook* add = new Rook("white", 7, 0);
        Rook* add1 = new Rook("white", 7, 7);
        playerWhite.push_back(add);
        playerWhite.push_back(add1);

        Rook* add2 = new Rook("black", 0, 0);
        Rook* add3 = new Rook("black", 0, 7);
        playerBlack.push_back(add2);
        playerBlack.push_back(add3);

    }

    void createKnights() {
        Knight* add = new Knight("white", 7, 1);
        Knight* add1 = new Knight("white", 7, 6);
        playerWhite.push_back(add);
        playerWhite.push_back(add1);

        Knight* add2 = new Knight("black", 0, 1);
        Knight* add3 = new Knight("black", 0, 6);
        playerBlack.push_back(add2);
        playerBlack.push_back(add3);

    }
    
    void createQueens() {
        Queen* add = new Queen("white", 7, 4);
        playerWhite.push_back(add);

        Queen* add1 = new Queen("black", 0, 4);
        playerBlack.push_back(add1);
    }

    void createKings() {
        King* add = new King("white", 7, 3);
        playerWhite.push_back(add);

        King* add1 = new King("black", 0, 3);
        playerBlack.push_back(add1);
    }


    void close() {
        while(!playerBlack.empty() && !playerWhite.empty()) {
            delete playerBlack.front();
            playerBlack.pop_front();

            delete playerWhite.front();
            playerWhite.pop_front();
        }

    }