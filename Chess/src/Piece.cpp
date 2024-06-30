#include <utility>
#include "../include/Piece.h"

// Default constructor initializing members to default values
Piece::Piece() : color(' '), PieceCords({0, 0}), chess(nullptr) {}

// Returns the current position of the piece
std::pair<int, int> Piece::PiecePlace() const {
    return PieceCords;
}

// Assignment operator for copying values from another piece
Piece& Piece::operator=(const Piece& rhs) {
    if (this != &rhs) { // Protect against self-assignment
        color = rhs.GetColor();  // Use getter for color if encapsulated
        PieceCords = rhs.PiecePlace(); // Use the existing getter for coordinates
        chess = rhs.chess; // Direct copy of the pointer
    }
    return *this;
}

// Constructor initializing all member variables
Piece::Piece(char color, std::pair<int, int> Cord, Chess* chess)
    : color(color), PieceCords(std::move(Cord)), chess(chess) {
}
