#include "../include/King.h"
#include "../include/Chess.h"

King::King(char color, std::pair<int, int> kingCord, Chess* chessObj) 
    : Piece(color, kingCord, chessObj) {
    this->color = color;
    this->pieceCords = kingCord;
}

King::King() = default;

std::pair<int, int> King::piecePlace() const {
    return this->pieceCords;
}

std::vector<std::pair<int, int>> King::pieceMoves() const {
    std::vector<std::pair<int, int>> moves;
    const int max = 17;
    const int min = 3;
    int downRow = pieceCords.first + 2;
    int upRow = pieceCords.first - 2;
    int leftCol = pieceCords.second - 2;
    int rightCol = pieceCords.second + 2;

    if (upRow > min && this->chess->getPieceAt(upRow, pieceCords.second) == ' ')
        moves.emplace_back(upRow, pieceCords.second);

    if (upRow > min && rightCol < max && this->chess->getPieceAt(upRow, rightCol) == ' ')
        moves.emplace_back(upRow, rightCol);

    if (upRow > min && leftCol > min && this->chess->getPieceAt(upRow, leftCol) == ' ')
        moves.emplace_back(upRow, leftCol);

    if (rightCol < max && this->chess->getPieceAt(pieceCords.first, rightCol) == ' ')
        moves.emplace_back(pieceCords.first, rightCol);

    if (leftCol > min && this->chess->getPieceAt(pieceCords.first, leftCol) == ' ')
        moves.emplace_back(pieceCords.first, leftCol);

    if (downRow < max && this->chess->getPieceAt(downRow, pieceCords.second) == ' ')
        moves.emplace_back(downRow, pieceCords.second);

    if (downRow < max && rightCol < max && this->chess->getPieceAt(downRow, rightCol) == ' ')
        moves.emplace_back(downRow, rightCol);

    if (downRow < max && leftCol > min && this->chess->getPieceAt(downRow, leftCol) == ' ')
        moves.emplace_back(downRow, leftCol);

    return moves;
}

Piece& King::operator=(const Piece& rhs) {
    if (this != &rhs) {
        Piece::operator=(rhs);
    }
    return *this;
}

void King::setPiecePlace(std::pair<int, int> newCords) {
    this->pieceCords = newCords;
}

bool King::isInDanger() {
    const int max = 17;
    const int min = 3;
    bool isBlack = (color == 'b');

    for (int i = 1; i < 7; ++i) {
        int downRow = pieceCords.first + (i * 2);
        int upRow = pieceCords.first - (i * 2);
        int leftCol = pieceCords.second - (i * 2);
        int rightCol = pieceCords.second + (i * 2);

        if (downRow < max) {
            char piece = chess->getPieceAt(downRow, pieceCords.second);
            if ((isBlack && (piece == 'R' || piece == 'Q' || piece == 'K')) || (!isBlack && (piece == 'r' || piece == 'q' || piece == 'k'))) {
                return true;
            }
        }

        if (upRow > min) {
            char piece = chess->getPieceAt(upRow, pieceCords.second);
            if ((isBlack && (piece == 'R' || piece == 'Q' || piece == 'K')) || (!isBlack && (piece == 'r' || piece == 'q' || piece == 'k'))) {
                return true;
            }
        }

        if (leftCol > min) {
            char piece = chess->getPieceAt(pieceCords.first, leftCol);
            if ((isBlack && (piece == 'R' || piece == 'Q' || piece == 'K')) || (!isBlack && (piece == 'r' || piece == 'q' || piece == 'k'))) {
                return true;
            }
        }

        if (rightCol < max) {
            char piece = chess->getPieceAt(pieceCords.first, rightCol);
            if ((isBlack && (piece == 'R' || piece == 'Q' || piece == 'K')) || (!isBlack && (piece == 'r' || piece == 'q' || piece == 'k'))) {
                return true;
            }
        }

        if (downRow < max && leftCol > min) {
            char piece = chess->getPieceAt(downRow, leftCol);
            if ((isBlack && (piece == 'B' || piece == 'Q' || piece == 'K')) || (!isBlack && (piece == 'b' || piece == 'q' || piece == 'p' || piece == 'k'))) {
                return true;
            }
        }

        if (downRow < max && rightCol < max) {
            char piece = chess->getPieceAt(downRow, rightCol);
            if ((isBlack && (piece == 'B' || piece == 'Q' || piece == 'K')) || (!isBlack && (piece == 'b' || piece == 'q' || piece == 'p' || piece == 'k'))) {
                return true;
            }
        }

        if (upRow > min && leftCol > min) {
            char piece = chess->getPieceAt(upRow, leftCol);
            if ((isBlack && (piece == 'B' || piece == 'Q' || piece == 'K')) || (!isBlack && (piece == 'b' || piece == 'q' || piece == 'P' || piece == 'k'))) {
                return true;
            }
        }

        if (upRow > min && rightCol < max) {
            char piece = chess->getPieceAt(upRow, rightCol);
            if ((isBlack && (piece == 'B' || piece == 'Q' || piece == 'K')) || (!isBlack && (piece == 'b' || piece == 'q' || piece == 'P' || piece == 'k'))) {
                return true;
            }
        }
    }

    return false;
}

char King::getType() {
    return (this->color == 'w') ? 'K' : 'k';
}
