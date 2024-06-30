#ifndef CHESS_PAWN_H
#define CHESS_PAWN_H

#include "Piece.h"
#include "Chess.h"
#include <vector>
#include <utility>

class Pawn : public Piece {
public:
    // Constructors
    Pawn(char color, std::pair<int, int> pawnCord, Chess* chessObj);
    Pawn();

    // Destructor - utilizing the default destructor provided by the compiler
    virtual ~Pawn() = default;

    // Overriding Piece methods
    std::pair<int, int> PiecePlace() const override;
    std::vector<std::pair<int, int>> PieceMoves() const override;
    void SetPiecePlace(std::pair<int, int> newCords) override;
    char getType() override;

    // Pawn-specific functionality
    bool TouchTheLine();

    // Disabled copy and assignment operations
    Pawn(const Pawn&) = delete;
    Pawn& operator=(const Pawn&) = delete;
};

#endif // CHESS_PAWN_H
