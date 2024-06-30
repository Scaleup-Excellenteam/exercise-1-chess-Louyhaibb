#include "../include/Knight.h"

using namespace std;

Knight::Knight(char color, std::pair<int, int> cord, Chess* chessObj)
    : Piece(color, cord, chessObj) {
    this->color = color;
    this->pieceCords = cord;
}

std::pair<int, int> Knight::piecePlace() const {
    return Piece::piecePlace();
}

std::vector<std::pair<int, int>> Knight::pieceMoves() const {
    const int rightMaxColLim = 17;
    const int leftMaxColLim = 3;
    const int maxRow = 17;
    const int minRow = 3;
    
    std::vector<std::pair<int, int>> moves;
    int knightCordRow = this->pieceCords.first;
    int knightCordCol = this->pieceCords.second;

    if (knightCordRow + 2 <= maxRow) {
        if (knightCordCol + 4 <= rightMaxColLim) {
            moves.emplace_back(knightCordRow + 4, knightCordCol + 2);
        }
        if (knightCordCol - 4 >= leftMaxColLim) {
            moves.emplace_back(knightCordRow + 4, knightCordCol - 2);
        }
    }
    if (knightCordRow - 4 >= minRow) {
        if (knightCordCol + 2 <= rightMaxColLim) {
            moves.emplace_back(knightCordRow - 4, knightCordCol + 2);
        }
        if (knightCordCol - 2 >= leftMaxColLim) {
            moves.emplace_back(knightCordRow - 4, knightCordCol - 2);
        }
    }
    if (knightCordCol + 4 <= rightMaxColLim) {
        if (knightCordRow + 2 <= maxRow) {
            moves.emplace_back(knightCordRow + 2, knightCordCol + 4);
        }
        if (knightCordRow - 2 >= minRow) {
            moves.emplace_back(knightCordRow - 2, knightCordCol + 4);
        }
    }
    if (knightCordCol - 4 >= leftMaxColLim) {
        if (knightCordRow + 2 <= maxRow) {
            moves.emplace_back(knightCordRow + 2, knightCordCol - 4);
        }
        if (knightCordRow - 2 <= maxRow) {
            moves.emplace_back(knightCordRow - 2, knightCordCol - 4);
        }
    }
    return moves;
}

Piece& Knight::operator=(const Piece& rhs) {
    if (this != &rhs) {
        Piece::operator=(rhs);
    }
    return *this;
}

void Knight::setPiecePlace(std::pair<int, int> newCords) {
    this->pieceCords = newCords;
}

char Knight::getType() {
    return (this->color == 'w') ? 'N' : 'n';
}

Knight::Knight() = default;
