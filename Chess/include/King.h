#ifndef CHESS_KING_H
#define CHESS_KING_H

#include "Piece.h"

class King : public Piece {
public:
‎    // קונסטרקטור עם צבע וקורדינטות
    explicit King(char color, std::pair<int, int> pawnCord, Chess* chessObj);

‎    // קונסטרקטור ברירת מחדל
    King();

‎    // החזרת מיקום הכלי
    virtual std::pair<int, int> piecePlace() const override;

‎    // החזרת תנועות אפשריות של הכלי
    virtual std::vector<std::pair<int, int>> pieceMoves() const override;

‎    // השמה של הכלי
    Piece& operator=(const Piece& rhs) override;

‎    // הגדרת מיקום חדש לכלי
    void setPiecePlace(std::pair<int, int> newCords) override;

‎    // בדיקה אם המלך בסכנה
    bool isInDanger();

‎    // קבלת סוג הכלי
    char getType() override;
};

#endif // CHESS_KING_H
