#include "../include/King.h"
#include "../include/Chess.h"

King::King(char color, std::pair<int, int> kingCord, Chess* chessObj) 
    : Piece(color, kingCord, chessObj) {
    this->color = color;
    this->PieceCords = kingCord;
}

King::King() = default;

std::pair<int, int> King::PiecePlace() const {
    return this->PieceCords;
}

std::vector<std::pair<int, int>> King::PieceMoves() const {
    std::vector<std::pair<int, int>> moves;
    const int max = 17;
    const int min = 3;
    int downRow = PieceCords.first + 2;
    int upRow = PieceCords.first - 2;
    int leftCol = PieceCords.second - 2;
    int rightCol = PieceCords.second + 2;

    if (upRow > min && this->chess->GetPieceAt(upRow, PieceCords.second) == ' ')
        moves.emplace_back(upRow, PieceCords.second);

    if (upRow > min && rightCol < max && this->chess->GetPieceAt(upRow, rightCol) == ' ')
        moves.emplace_back(upRow, rightCol);

    if (upRow > min && leftCol > min && this->chess->GetPieceAt(upRow, leftCol) == ' ')
        moves.emplace_back(upRow, leftCol);

    if (rightCol < max && this->chess->GetPieceAt(PieceCords.first, rightCol) == ' ')
        moves.emplace_back(PieceCords.first, rightCol);

    if (leftCol > min && this->chess->GetPieceAt(PieceCords.first, leftCol) == ' ')
        moves.emplace_back(PieceCords.first, leftCol);

    if (downRow < max && this->chess->GetPieceAt(downRow, PieceCords.second) == ' ')
        moves.emplace_back(downRow, PieceCords.second);

    if (downRow < max && rightCol < max && this->chess->GetPieceAt(downRow, rightCol) == ' ')
        moves.emplace_back(downRow, rightCol);

    if (downRow < max && leftCol > min && this->chess->GetPieceAt(downRow, leftCol) == ' ')
        moves.emplace_back(downRow, leftCol);

    return moves;
}

Piece& King::operator=(const Piece& rhs) {
    if (this != &rhs) {
        Piece::operator=(rhs);
    }
    return *this;
}

void King::SetPiecePlace(std::pair<int, int> newCords) {
    this->PieceCords = newCords;
}

bool King::isInDanger() {
    const int max = 17;
    const int min = 3;
    bool isBlack = (color == 'b');

    for (int i = 1; i < 7; ++i) {
        int downRow = PieceCords.first + (i * 2);
        int upRow = PieceCords.first - (i * 2);
        int leftCol = PieceCords.second - (i * 2);
        int rightCol = PieceCords.second + (i * 2);

        if (downRow < max) {
            char piece = chess->GetPieceAt(downRow, PieceCords.second);
            if ((isBlack && (piece == 'R' || piece == 'Q' || piece == 'K')) || (!isBlack && (piece == 'r' || piece == 'q' || piece == 'k'))) {
                return true;
            }
        }

        if (upRow > min) {
            char piece = chess->GetPieceAt(upRow, PieceCords.second);
            if ((isBlack && (piece == 'R' || piece == 'Q' || piece == 'K')) || (!isBlack && (piece == 'r' || piece == 'q' || piece == 'k'))) {
                return true;
            }
        }

        if (leftCol > min) {
            char piece = chess->GetPieceAt(PieceCords.first, leftCol);
            if ((isBlack && (piece == 'R' || piece == 'Q' || piece == 'K')) || (!isBlack && (piece == 'r' || piece == 'q' || piece == 'k'))) {
                return true;
            }
        }

        if (rightCol < max) {
            char piece = chess->GetPieceAt(PieceCords.first, rightCol);
            if ((isBlack && (piece == 'R' || piece == 'Q' || piece == 'K')) || (!isBlack && (piece == 'r' || piece == 'q' || piece == 'k'))) {
                return true;
            }
        }

        if (downRow < max && leftCol > min) {
            char piece = chess->GetPieceAt(downRow, leftCol);
            if ((isBlack && (piece == 'B' || piece == 'Q' || piece == 'K')) || (!isBlack && (piece == 'b' || piece == 'q' || piece == 'p' || piece == 'k'))) {
                return true;
            }
        }

        if (downRow < max && rightCol < max) {
            char piece = chess->GetPieceAt(downRow, rightCol);
            if ((isBlack && (piece == 'B' || piece == 'Q' || piece == 'K')) || (!isBlack && (piece == 'b' || piece == 'q' || piece == 'p' || piece == 'k'))) {
                return true;
            }
        }

        if (upRow > min && leftCol > min) {
            char piece = chess->GetPieceAt(upRow, leftCol);
            if ((isBlack && (piece == 'B' || piece == 'Q' || piece == 'K')) || (!isBlack && (piece == 'b' || piece == 'q' || piece == 'P' || piece == 'k'))) {
                return true;
            }
        }

        if (upRow > min && rightCol < max) {
            char piece = chess->GetPieceAt(upRow, rightCol);
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