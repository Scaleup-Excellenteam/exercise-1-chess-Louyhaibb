#pragma once
#include <iostream>
#include <windows.h>
#include <string>

using std::cout;
using std::cin; 
using std::endl;
using std::string;

const int BOARD_SIZE = 21;

class Chess {
private:
    unsigned char board[BOARD_SIZE][BOARD_SIZE] = { 0 };
    bool turn = true;
    string boardString;
    string input;
    string msg = "\n";
    string errorMsg = "\n";
    int codeResponse;

    void clear() const;
    void setFrames();
    void setPieces();
    void show() const;
    void displayBoard() const;
    void showAskInput() const;
    bool isSame() const;
    bool isValid() const;
    bool isExit() const;
    void execute();
    void doTurn();

public:
    explicit Chess(const string& start = "RNBQKBNRPPPPPPPP################################pppppppprnbqkbnr");
    
    Chess(const Chess&) = delete;
    Chess& operator=(const Chess&) = delete;
    
    string getInput();
    void setCodeResponse(int codeResponse);
    char getPieceAt(int row, int col) const;
    bool getTurn() const { return turn; }
    void setBoard(std::pair<int, int> cord, char piece) { board[cord.first][cord.second] = piece; }
};


void Chess::clear() const {
    system("cls");
}

void Chess::setFrames() {}

void Chess::setPieces() {}

void Chess::show() const {}

void Chess::displayBoard() const {
‎    // פונקציה להצגת הלוח על המסך
‎    // קוד מתאים להצגת הלוח
}

void Chess::showAskInput() const {
‎    // פונקציה להצגת בקשת קלט מהמשתמש
‎    // קוד מתאים להצגת בקשת קלט
}

bool Chess::isSame() const {
    
    return false;
}

bool Chess::isValid() const {

    return false;
}

bool Chess::isExit() const {
 
    return false;
}

void Chess::execute() {
 
}

void Chess::doTurn() {

}

string Chess::getInput() {
    
    return input;
}

void Chess::setCodeResponse(int codeResponse) {
  
    this->codeResponse = codeResponse;
}

char Chess::getPieceAt(int row, int col) const {
  
    return board[row][col];
}
