#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H

#include <utility>
#include <vector>

#include "Chess.h"
class Piece {
protected:
    char color;
    std::pair<int, int> PieceCords;
    Chess *  chess;
public:
    Piece();
    Piece(char color, std::pair<int, int> Cord, Chess* chess);
    virtual ~Piece() = default; // Destructor for proper cleanup in derived classes
    virtual std::pair<int, int> PiecePlace() const; // Making this method const
    virtual std::vector<std::pair<int, int>> PieceMoves() const = 0; // Pure virtual function for derived classes
    virtual Piece& operator=(const Piece& rhs);
    char GetColor() const { return color; }
    virtual void SetPiecePlace(std::pair<int, int> newCords) = 0;
    bool IsDead() const {return  isDead;}
    void SetIsDead(bool Case) {isDead = Case;};
    virtual char getType() = 0;

private:
    bool isDead = false;
};

#endif // CHESS_PIECE_H
