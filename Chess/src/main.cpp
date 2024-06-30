// Chess
#include "../include/Chess.h"
#include "../include/GameLogic.h"
int main()
{
	string board = "RNBQKBNRPPPPPPPP################################pppppppprnbqkbnr";
	Chess *a = new Chess(board);
    auto *gameLogic = new GameLogic(a);
	string res = a->getInput();

    while (res != "exit")
	{
		/*
		codeResponse value :
		Illegal movements :
		11 - there is not piece at the source
		12 - the piece in the source is piece of your opponent
		13 - there one of your pieces at the destination
		21 - illegal movement of that piece
		31 - this movement will cause you checkmate

		legal movements :
		41 - the last movement was legal and cause check
		42 - the last movement was legal, next turn
		*/
        int response = gameLogic->ProcessTheInput(res);
        a->setCodeResponse(response);
        res = a->getInput();
	}
	cout << endl << "Exiting " << endl;
	return 0;
}