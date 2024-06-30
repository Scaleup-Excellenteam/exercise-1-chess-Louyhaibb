#ifndef CHESS_GAMELOGIC_H
#define CHESS_GAMELOGIC_H

#include <string>
#include <vector>

class Bishop;
class Knight;
class Piece;
class Chess;

class GameLogic {
private:
    std::vector<Piece*> pieces;
    Chess* chess;

‎    // יצירת מערכי הכלים
    void piecesArrays();
    void pawnArrays();
    void bishopArrays();
    void knightArrays();
    void queenArrays();
    void rockArrays();
    void kingArrays();

‎    // בדיקת תנועה
    int checkMovement(const std::vector<std::pair<int, int>>& cords);

‎    // חיפוש כלי לפי קורדינטות
    Piece* searchForPiece(std::pair<int, int> cords);

‎    // טיפול בתגובת הקוד
    void codeResponseHandle(int codeResponse, std::pair<int, int>& oldCords, std::pair<int, int>& newCords, char pieceType);

‎    // החזרת המלך לפי צבע
    Piece* getKing(char color);

public:
‎    // קונסטרקטור
    GameLogic(Chess* chess);

‎    // דה-קונסטרקטור
    ~GameLogic();

‎    // עיבוד קלט
    int processTheInput(const std::string& input);
};

#endif // CHESS_GAMELOGIC_H
