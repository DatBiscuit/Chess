#include <stdio.h>

    const int boardSize = 8;

    void printBoard();

    int main(int argc, char* argv[]) {
        printBoard();

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
