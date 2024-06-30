#include "../include/Queen.h"
#include "../include/Chess.h"

// Constructor initializes the base class and sets member variables directly
Queen::Queen(char color, std::pair<int, int> QueenCord, Chess *chessObj) : Piece(color, QueenCord, chessObj) {}

// Default constructor
Queen::Queen() = default;

// Return the current position of the queen
std::pair<int, int> Queen::PiecePlace() const {
    return Piece::PiecePlace();
}

// Calculate all possible moves for the queen considering board boundaries
std::vector<std::pair<int, int>> Queen::PieceMoves() const {
    std::vector<std::pair<int, int>> Moves;
    int max = 17;  // Assuming this is the max board boundary
    int min = 3;   // Assuming this is the min board boundary

    // Directions for Queen's movement (horizontal, vertical, and diagonal)
    std::vector<std::pair<int, int>> directions = {
        {2, 0}, {0, 2}, {-2, 0}, {0, -2},  // Vertical and horizontal
        {2, 2}, {2, -2}, {-2, 2}, {-2, -2} // Diagonal
    };

    for (const auto& direction : directions) {
        int newRow = this->PieceCords.first;
        int newCol = this->PieceCords.second;

        // Extend the move in the current direction until hitting the boundary or another piece
        while (true) {
            newRow += direction.first;
            newCol += direction.second;

            // Check if the new position is within board boundaries
            if (newRow >= min && newRow < max && newCol >= min && newCol < max) {
                char pieceAtNewPos = chess->GetPieceAt(newRow, newCol);
                if (pieceAtNewPos == ' ') {
                    Moves.emplace_back(newRow, newCol);
                } else {
                    if (pieceAtNewPos != this->color) {
                        Moves.emplace_back(newRow, newCol);  // Capture the piece
                    }
                    break;  // Stop extending in this direction
                }
            } else {
                break;  // Out of board boundaries
            }
        }
    }

    return Moves;
}

// Assignment operator to ensure proper copy semantics
Piece &Queen::operator=(const Piece &rhs) {
    if (this != &rhs) {
        Piece::operator=(rhs);
    }
    return *this;
}

// Set new coordinates for the queen
void Queen::SetPiecePlace(std::pair<int, int> newCords) {
    this->PieceCords = newCords;
}

// Get the type of the piece based on its color
char Queen::getType() {
    return this->color == 'w' ? 'Q' : 'q';
}
