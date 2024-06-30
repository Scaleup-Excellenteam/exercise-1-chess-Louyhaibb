#include "../include/Bishop.h"
#include <vector>
#include <utility>

using namespace std;

Bishop::Bishop() = default;

Bishop::Bishop(char color, std::pair<int, int> cord, Chess* chessObj) 
    : Piece(color, cord, chessObj) {}

std::pair<int, int> Bishop::piecePlace() const {
    return this->pieceCords;
}

std::vector<std::pair<int, int>> Bishop::pieceMoves() const {
    // This is vars for knowing were the lim of the col and the row
    const int rightMaxColLim = 17;
    const int leftMaxColLim = 3;
    const int maxRow = 17;
    const int minRow = 3;
    
    // vector for storing the moves of the piece
    vector<std::pair<int, int>> moves;

    // offset to the next move
    int index = 2;

    // flags to exit if we hit all the possible moves
    bool flag = true;
    bool subFlag = true;
    bool subFlag2 = true;
    int row, col;

    while (flag) {
        // to get to the next position in the board
        // if it is a white piece we move down by adding to the row
        if (color == 'w') 
            row = this->pieceCords.first + index;
        // if it is a black piece we move up by subtracting from the row
        else 
            row = this->pieceCords.first - index;
        
        col = this->pieceCords.second + index;
        
        // Assuming Chess::getPieceAt is a function that returns the piece at the given coordinates
        char piece = chess->getPieceAt(row, col);
        if (piece == ' ' && col <= rightMaxColLim && subFlag) {
            moves.emplace_back(row, col);
        } else {
            moves.emplace_back(row, col);
            subFlag = false;
        }

        int leftCol = this->pieceCords.second - index;
        char leftPiece = chess->getPieceAt(row, leftCol);

        // if we hit an empty spot that in the move direction for the piece
        if (leftPiece == ' ' && leftCol >= leftMaxColLim && subFlag2) {
            moves.emplace_back(row, leftCol);
        } else {
            moves.emplace_back(row, leftCol);
            subFlag2 = false;
        }

        index += 2;

        // if we don't have any position left to cover we exit
        if (!subFlag && !subFlag2) {
            flag = false;
        }
    }
    return moves;
}

Piece& Bishop::operator=(const Piece& rhs) {
    if (this != &rhs) {
        Piece::operator=(rhs); // Call base class assignment operator
        this->pieceCords = rhs.piecePlace(); // Assuming piecePlace returns the coordinates
    }
    return *this;
}

void Bishop::setPiecePlace(std::pair<int, int> newCords) {
    this->pieceCords = newCords;
}

char Bishop::getType() {
    return (this->color == 'w') ? 'B' : 'b';
}
