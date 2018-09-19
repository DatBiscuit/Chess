#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <list>
#include <algorithm>
#include <Board.h>


using namespace std;

    void close();

    int main(int argc, char* argv[]) {
        Board board;
        board.initBoard();
        board.printBoard();


        return 0;
    }