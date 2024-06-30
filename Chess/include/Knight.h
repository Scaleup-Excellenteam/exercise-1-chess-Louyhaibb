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

    virtual std::pair<int, int> piecePlace() const override;

    virtual std::vector<std::pair<int, int>> pieceMoves() const override;

    virtual Piece& operator=(const Piece& rhs) override;

    void setPiecePlace(std::pair<int, int> newCords) override;

    char getType() override;
};

#endif // CHESS_KNIGHT_H
