#include <stdlib.h>
#include <stdio.h>
#include <Board.h>
#include <string>
#include <iostream>
#include <ctype.h>

    bool checkForValidInput(std::string userInput);
    bool boardChanges(Board oldBoard, std::string userInput, bool whitesTurn);

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

            if(!checkForValidInput(input)) {
                cout << "Invalid Input" << endl;
                continue;
            }
            if(!board.gamepieceAtSpot(input[1] - '0', input[0] -'a')) {
                cout << "No piece at that spot" << endl;
                continue;
            }
            if(!boardChanges(board, input, whitesTurn)) {
                continue;
            }

            whitesTurn = !whitesTurn;
        }



        return 0;
    }

    bool boardChanges(Board oldBoard, std::string userInput, bool whitesTurn) {
        int currY = userInput[0] - 'a';
        int currX = userInput[1] - '0';
        int newY = userInput[3] - 'a';
        int newX = userInput[4] - '0';
        if(oldBoard.gamepieceAtSpot(newX, newY)) {
            cout << "There is a Game Piece at that location" << endl;
            return false;
        }
        if(!oldBoard.rightColorPiece(whitesTurn, currX, currY)) {
            cout << "Invalid Selection of Chess Piece, that is not your Piece" << endl;
            return false;
        }
        if (!oldBoard.updateBoard(currX, currY, newX, newY)) {
            cout << "Invalid Move, Chess Piece cannot move like that" << endl;
            return false;
        }
        return true;
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