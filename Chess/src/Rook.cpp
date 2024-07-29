#include "../include/Rook.h"
#include "../include/Chess.h"

const int BOARD_SIZE = 8;  // Assuming a standard 8x8 chess board

Rook::Rook(char color, std::pair<int, int> rockCord, Chess *chessObj)
    : Piece(color, rockCord, chessObj) {}

Rook::Rook() = default;

std::pair<int, int> Rook::PiecePlace() const {
    return PieceCords;
}

Piece &Rook::operator=(const Piece &rhs) {
    if (this != &rhs) {
        Piece::operator=(rhs);
    }
    return *this;
}

void Rook::SetPiecePlace(std::pair<int, int> newCords) {
    PieceCords = newCords;
}

std::vector<std::pair<int, int>> Rook::PieceMoves() const {
    std::vector<std::pair<int, int>> Moves;
    const int step = 2; // Step multiplier, assuming every second square is valid

    // Scan in four directions: right, left, down, up
    for (int dir = -1; dir <= 1; dir += 2) {
        for (int dist = step; dist < BOARD_SIZE; dist += step) {
            int newCol = PieceCords.second + dir * dist;
            int newRow = PieceCords.first + dir * dist;

            // Check horizontal moves within board bounds
            if (newCol >= 0 && newCol < BOARD_SIZE) {
                if (chess->GetPieceAt(PieceCords.first, newCol) == ' ' ||
                    chess->GetPieceAt(PieceCords.first, newCol) != color) {
                    Moves.emplace_back(PieceCords.first, newCol);
                }
            }

            // Check vertical moves within board bounds
            if (newRow >= 0 && newRow < BOARD_SIZE) {
                if (chess->GetPieceAt(newRow, PieceCords.second) == ' ' ||
                    chess->GetPieceAt(newRow, PieceCords.second) != color) {
                    Moves.emplace_back(newRow, PieceCords.second);
                }
            }
        }
    }

    return Moves;
}

char Rook::getType() {
    return color == 'w' ? 'R' : 'r';
}
