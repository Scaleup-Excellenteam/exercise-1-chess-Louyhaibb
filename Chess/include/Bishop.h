#ifndef CHESS_BISHOP_H
#define CHESS_BISHOP_H

#include "Piece.h"
#include <vector>
#include <utility>

class Chess;  // Forward declaration if Chess.h is not required for the header

class Bishop : public Piece {
public:
    Bishop();
    Bishop(char color, std::pair<int, int> Cord, Chess* chessObj);
    std::pair<int, int> PiecePlace() const override;
    std::vector<std::pair<int, int>> PieceMoves() const override;
    Piece& operator=(const Piece& rhs) override;
    void SetPiecePlace(std::pair<int, int> newCords) override;
    char getType() override;
};

#endif // CHESS_BISHOP_H
