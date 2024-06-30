#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H

#include <utility>
#include <vector>

class Chess;  // Forward declaration of Chess

class Piece {
protected:
    char color;
    std::pair<int, int> PieceCords;
    Chess* chess;

public:
    // Constructors
    Piece();
    Piece(char color, std::pair<int, int> Cord, Chess* chess);

    // Virtual destructor for proper cleanup in derived classes
    virtual ~Piece() = default;

    // Virtual methods to be overridden in derived classes
    virtual std::pair<int, int> PiecePlace() const;
    virtual std::vector<std::pair<int, int>> PieceMoves() const = 0;
    virtual void SetPiecePlace(std::pair<int, int> newCords) = 0;
    virtual char getType() = 0;

    // Common methods
    char GetColor() const { return color; }
    bool IsDead() const { return isDead; }
    void SetIsDead(bool Case) { isDead = Case; }

    // Assignment operator
    Piece& operator=(const Piece& rhs);

private:
    bool isDead = false;
};

#endif // CHESS_PIECE_H
