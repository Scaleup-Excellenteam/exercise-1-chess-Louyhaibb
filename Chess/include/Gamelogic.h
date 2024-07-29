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

    void piecesArrays();
    void pawnArrays();
    void bishopArrays();
    void knightArrays();
    void queenArrays();
    void rockArrays();
    void kingArrays();

    int checkMovement(const std::vector<std::pair<int, int>>& cords);

    Piece* searchForPiece(std::pair<int, int> cords);

    void codeResponseHandle(int codeResponse, std::pair<int, int>& oldCords, std::pair<int, int>& newCords, char pieceType);

    Piece* getKing(char color);

public:
    GameLogic(Chess* chess);

    ~GameLogic();

    int processTheInput(const std::string& input);
};

#endif // CHESS_GAMELOGIC_H
