#ifndef CHESS_QUEEN_H
#define CHESS_QUEEN_H

#include "Piece.h"
#include "Chess.h"
#include <vector>
#include <utility>

class Queen : public Piece {
public:
    // Constructors
    Queen(char color, std::pair<int, int> QueenCord, Chess* chessObj);
    Queen();

    // Destructor - utilizing the default destructor provided by the compiler
    virtual ~Queen() = default;

    // Overriding Piece methods
    std::pair<int, int> PiecePlace() const override;
    std::vector<std::pair<int, int>> PieceMoves() const override;
    void SetPiecePlace(std::pair<int, int> newCords) override;
    char getType() override;

    // Disabled copy and assignment operations
    Queen(const Queen&) = delete;
    Queen& operator=(const Queen&) = delete;
};

#endif // CHESS_QUEEN_H
