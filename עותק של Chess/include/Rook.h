#ifndef CHESS_ROOK_H
#define CHESS_ROOK_H

#include "Piece.h"

class Rook : public Piece {
public:
    explicit Rook(char color, std::pair<int, int> position, Chess* chessGame);
    Rook();
    std::pair<int, int> PiecePlace() const override;
    std::vector<std::pair<int, int>> PieceMoves() const override;
    Piece& operator=(const Piece& rhs);
    void SetPiecePlace(std::pair<int, int> newCords) override;
    char getType() override;
};

#endif // CHESS_ROOK_H
