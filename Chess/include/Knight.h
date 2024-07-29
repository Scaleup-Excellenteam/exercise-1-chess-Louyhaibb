#ifndef CHESS_KNIGHT_H
#define CHESS_KNIGHT_H

#include <utility>
#include <string>
#include <vector>
#include "Piece.h"

class Knight : public Piece {
public:
    
    explicit Knight(char color, std::pair<int, int> pawnCord, Chess* chessObj);

    Knight();

    virtual std::pair<int, int> PiecePlace() const override;

    virtual std::vector<std::pair<int, int>> PieceMoves() const override;

    virtual Piece& operator=(const Piece& rhs) override;

    virtual  void SetPiecePlace(std::pair<int, int> newCords) override;

    char getType() override;
};

#endif // CHESS_KNIGHT_H
