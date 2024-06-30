#include "../include/GameLogic.h"
#include "../include/Chess.h"
#include "../include/Pawn.h"
#include "../include/Knight.h"
#include "../include/Bishop.h"
#include "../include/Rock.h"
#include "../include/Queen.h"
#include "../include/King.h"
#include <sstream>
#include <string>

using namespace std;

enum Behavior { Valid = 41, SamePiece, MoveOutOfRange };

GameLogic::GameLogic(Chess* chess) : chess(chess) {
    piecesArrays();
}

void GameLogic::piecesArrays() {
    pawnArrays();
    bishopArrays();
    knightArrays();
    rockArrays();
    queenArrays();
    kingArrays();
}

int GameLogic::processTheInput(const std::string& input) {
    stringstream ss(input);
    string token;
    vector<pair<int, int>> parsedInput;
    while (ss >> token) {
        pair<int, int> placeAsInteger = { 0, 0 };
        for (char ch : token) {
            if (isalpha(ch) && !islower(ch))
                placeAsInteger.first = ((ch - 'A') * 2) + 3;
            else if (isalpha(ch) && islower(ch))
                placeAsInteger.first = ((ch - 'a') * 2) + 3;
            else
                placeAsInteger.second = ((ch - '0') * 2) + 1;
        }
        parsedInput.push_back(placeAsInteger);
    }

    int code = checkMovement(parsedInput);
    codeResponseHandle(code, parsedInput[0], parsedInput[1], chess->getPieceAt(parsedInput[0].first, parsedInput[0].second));
    return code;
}

int GameLogic::checkMovement(const std::vector<std::pair<int, int>>& cords) {
    Piece* piece = searchForPiece(cords[0]);
    Piece* target = searchForPiece(cords[1]);

    if (piece) {
        if ((chess->getTurn() && piece->getColor() == 'b') || (!chess->getTurn() && piece->getColor() == 'w')) {
            return 12;
        }
        if (target && piece->getColor() == target->getColor()) {
            return 13;
        }
        vector<pair<int, int>> vec = piece->pieceMoves();
        for (const auto& move : vec) {
            if (move.first == cords[1].first && move.second == cords[1].second) {
                King* whiteKing = dynamic_cast<King*>(getKing('w'));
                King* blackKing = dynamic_cast<King*>(getKing('b'));
                bool whiteInDanger = false;
                bool blackInDanger = false;
                chess->setBoard(move, piece->getType());
                if (whiteKing)
                    whiteInDanger = whiteKing->isInDanger();

                if (blackKing)
                    blackInDanger = blackKing->isInDanger();

                if (whiteInDanger && chess->getTurn()) {
                    chess->setBoard(cords[0], piece->getType());
                    chess->setBoard(cords[1], ' ');
                    return 31;
                }

                if (blackInDanger && !chess->getTurn()) {
                    chess->setBoard(cords[0], piece->getType());
                    chess->setBoard(cords[1], ' ');
                    return 31;
                }
                if (whiteInDanger && !chess->getTurn())
                    return 41;
                if (blackInDanger && chess->getTurn())
                    return 41;
                if (target) {
                    target->setIsDead(true);
                }
                return 42;
            }
        }
        return 21;
    }
    return 11;
}

Piece* GameLogic::searchForPiece(pair<int, int> cords) {
    for (Piece* piece : pieces) {
        if (piece->piecePlace() == cords && !piece->isDead()) {
            return piece;
        }
    }
    return nullptr;
}

GameLogic::~GameLogic() {
    for (Piece* piece : pieces) {
        delete piece;
    }
}

void GameLogic::codeResponseHandle(int codeResponse, std::pair<int, int>& oldCords, std::pair<int, int>& newCords, char color) {
    if (codeResponse >= 41) {
        Piece* tmp = searchForPiece(oldCords);
        if (tmp)
            tmp->setPiecePlace(newCords);
    }
}

void GameLogic::pawnArrays() {
    for (int i = 1; i <= 8; i++) {
        pieces.push_back(new Pawn('w', { 5, (i * 2) + 1 }, chess));
    }
    for (int i = 1; i <= 8; i++) {
        pieces.push_back(new Pawn('b', { 15, (i * 2) + 1 }, chess));
    }
}

void GameLogic::knightArrays() {
    pieces.push_back(new Knight('w', { 3, 5 }, chess));
    pieces.push_back(new Knight('w', { 3, 17 }, chess));
    pieces.push_back(new Knight('b', { 17, 5 }, chess));
    pieces.push_back(new Knight('b', { 17, 17 }, chess));
}

void GameLogic::bishopArrays() {
    pieces.push_back(new Bishop('w', { 3, 7 }, chess));
    pieces.push_back(new Bishop('w', { 3, 15 }, chess));
    pieces.push_back(new Bishop('b', { 17, 7 }, chess));
    pieces.push_back(new Bishop('b', { 17, 15 }, chess));
}

void GameLogic::queenArrays() {
    pieces.push_back(new Queen('w', { 3, 9 }, chess));
    pieces.push_back(new Queen('b', { 17, 9 }, chess));
}

void GameLogic::rockArrays() {
    pieces.push_back(new Rock('w', { 3, 3 }, chess));
    pieces.push_back(new Rock('w', { 3, 17 }, chess));
    pieces.push_back(new Rock('b', { 17, 3 }, chess));
    pieces.push_back(new Rock('b', { 17, 17 }, chess));
}

void GameLogic::kingArrays() {
    pieces.push_back(new King('w', { 3, 11 }, chess));
    pieces.push_back(new King('b', { 17, 11 }, chess));
}

Piece* GameLogic::getKing(char color) {
    for (Piece* piece : pieces) {
        if ((color == 'w' && piece->getType() == 'K') || (color == 'b' && piece->getType() == 'k'))
            return piece;
    }
    return nullptr;
}
