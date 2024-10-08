#pragma once
#include "PionGenerique.h"

class MovementValidator
{
public:	
	MovementValidator();
	~MovementValidator();

	bool Excute(int xDep, int yDep, int xArr, int yArr, PionGenerique* board[8][8], char currentPlayer);

private:
	bool isPathClear(int xDep, int yDep, int xArr, int yArr, PionGenerique* board[8][8]);
	bool isPathClearDiagonal(int xDep, int yDep, int xArr, int yArr, PionGenerique* board[8][8]);
	bool isPathClearVertical(int xDep, int yDep, int xArr, int yArr, PionGenerique* board[8][8]);
	bool isPathClearHorizontal(int xDep, int yDep, int xArr, int yArr, PionGenerique* board[8][8]);

};

