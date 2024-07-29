#ifndef CHESS_KING_H
#define CHESS_KING_H

#include "Piece.h"

class King : public Piece {
public:
    explicit King(char color, std::pair<int, int> pawnCord, Chess* chessObj);

    King();

    virtual std::pair<int, int> PiecePlace() const override;

    virtual std::vector<std::pair<int, int>> PieceMoves() const override;

    Piece& operator=(const Piece& rhs) ;

    void SetPiecePlace(std::pair<int, int> newCords) override ;

    bool isInDanger();

    char getType() override;
};

#endif // CHESS_KING_H
