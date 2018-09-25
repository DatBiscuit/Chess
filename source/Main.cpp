#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <Board.h>

#define TESTING false

    bool checkForValidInput(std::string userInput);
    void boardChanges(Board oldBoard, std::string userInput);

    int main(int argc, char* argv[]) {

        std::string input = "";
        Board board;
        bool whitesTurn = true;

        board.initBoard();

        if(TESTING == true){
            printf("\n########## PROGRAM IS IN TEST MODE (=^ 3 ^=) ##########\n\n");
            printf("\n ---------------- BEGIN TESTING ----------------\n\n");

            string delimiter = ",";
            string testCase; 
            string caseNum;
            string moveInput;
            
            //Create file object for input
            ifstream testFile;
            testFile.open("../testing/chess_test_cases.txt");
            if(!testFile){
                cerr << "Unable to open file ../testing/chess_test_cases.txt";
                exit(1);
            }

            while(!testFile.eof()){
                //Parse line by line and get case num and move input
                getline(testFile, testCase);
                size_t pos = testCase.find(delimiter);
                caseNum = testCase.substr(0, pos);
                moveInput = testCase.substr(pos+1, string::npos);
                cout << caseNum << " => " << moveInput << endl;

                //Test the case
                printf("Before move\n");
                board.printBoard();
                if(!checkForValidInput(moveInput)) {
                    cout << "Invalid Input" << endl;
                }
                else if(!board.gamepieceAtSpot(moveInput[1] - '0', moveInput[0] -'a')) {
                    cout << "No piece at that spot" << endl;
                }
                else { 
                    boardChanges(board, moveInput);
                }
                printf("After move\n");
                board.printBoard();
                printf("\n\n");
            }
            testFile.close();
            printf("\n ---------------- END OF TESTING ----------------\n\n");
        }
        else{
            printf("\n########## PROGRAM IS IN USER INPUT MODE (=* 3 *=) ##########\n\n");
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

            }
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
