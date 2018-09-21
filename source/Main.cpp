#include <stdlib.h>
#include <stdio.h>
#include <Board.h>
#include <string>
#include <iostream>
#include <ctype.h>

    bool checkForValidInput(std::string userInput);
    void boardChanges(Board oldBoard, std::string userInput);

    int main(int argc, char* argv[]) {
        std::string input = "";
        Board board;
        bool whitesTurn = true;

        board.initBoard();

        while(input.compare("quit") != 0) {
            board.printBoard();
            if(whitesTurn) {
                cout << "Player White's Turn" << endl;
            } else {
                cout << "Player Black's Turn" << endl;
            }
            getline(cin,input);
            while (!checkForValidInput(input)) {
                cout << "Invalid Input" << endl;
                getline(cin,input);
            }
            while(!board.gamepieceAtSpot(input[1] - '0', input[0] -'a')) {
                cout << "No piece at that spot" << endl;
                getline(cin, input);
            }
            boardChanges(board, input);
            whitesTurn = !whitesTurn;
        }



        return 0;
    }

    void boardChanges(Board oldBoard, std::string userInput) {
        int currY = userInput[0] - 'a';
        int currX = userInput[1] - '0';
        int newY = userInput[3] - 'a';
        int newX = userInput[4] - '0';
        oldBoard.updateBoard(currX, currY, newX, newY);
    }

    bool checkForValidInput(std::string userInput) {

        if(userInput.length() > 5) {
            return false;
        }
        if(!isalpha(userInput[0]) || !isalpha(userInput[3])) {
            return false;

        }
        if(!isdigit(int(userInput[1])) || !isdigit(int(userInput[4]))) {
            return false;
            
        }

        if(userInput[0] >= 'a' && userInput[0] <= 'h' && userInput[3] >= 'a' && userInput[3] <= 'h') {
            if(userInput[1] - '0' >= 0 && userInput[1] - '0' <= 7 && userInput[4] - '0' >= 0 && userInput[4] - '0' <= 7) {
                if(isspace(userInput[2])) {
                    return true;
                }
            }
        }

        return false;
    }