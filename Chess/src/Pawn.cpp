#include "../include/Pawn.h"
#include <vector>
#include <iostream>
#include "../include/Chess.h"

using namespace std;

Pawn::Pawn(char color, std::pair<int, int> pawnCord, Chess* chessObj) : Piece(color, pawnCord, chessObj) {
    // ערכים אלו מוגדרים כבר במחלקת הבסיס ולכן לא צריך להגדיר אותם שוב כאן
}

Pawn::Pawn() : Piece() {}

std::pair<int, int> Pawn::PiecePlace() const {
    return PieceCords;
}

std::vector<std::pair<int, int>> Pawn::PieceMoves() const {
    vector<pair<int, int>> moves;
    int step = color == 'w' ? 2 : -2;  // מגדיר צעד של 2 משבצות קדימה או אחורה בהתאם לצבע

    // תנועה קדימה במשבצת אחת
    moves.emplace_back(PieceCords.first + step, PieceCords.second);

    // תנועה ראשונית של שתי משבצות
    if ((color == 'w' && PieceCords.first == 5) || (color == 'b' && PieceCords.first == 15)) {
        moves.emplace_back(PieceCords.first + 2 * step, PieceCords.second);
    }

    // אכילה באלכסון
    if (islower(chess->GetPieceAt(PieceCords.first + step, PieceCords.second + 2))) {
        moves.emplace_back(PieceCords.first + step, PieceCords.second + 2);
    }
    if (islower(chess->GetPieceAt(PieceCords.first + step, PieceCords.second - 2))) {
        moves.emplace_back(PieceCords.first + step, PieceCords.second - 2);
    }

    return moves;
}

Piece& Pawn::operator=(const Piece& rhs) {
    if (this != &rhs) {
        Piece::operator=(rhs);  // Call base class assignment operator
    }
    return *this;
}

void Pawn::SetPiecePlace(std::pair<int, int> newCords) {
    PieceCords = newCords;
}

bool Pawn::TouchTheLine() {
    // מחזיר אם הכלי נגע בקו הסוף של הלוח
    return color == 'w' ? PieceCords.first == 17 : PieceCords.first == 3;
}

char Pawn::getType() {
    return color == 'w' ? 'P' : 'p';
}
