#include <stdlib.h>
#include <stdio.h>
#include <Board.h>
#include <string>
#include <iostream>

    void close();

    int main(int argc, char* argv[]) {
        std::string input = "";
        Board board;
        bool whitesTurn = false;

        board.initBoard();
        board.printBoard();

        cout << "Player White's Turn" << endl;
        cin >> input;
        while(input.compare("quit") != 0) {
            board.printBoard();
            if(whitesTurn) {
                cout << "Player White's Turn" << endl;
                whitesTurn = false;
            } else {
                cout << "Player Black's Turn" << endl;
                whitesTurn = true;
            }
            cin >> input;
        }



        return 0;
    }