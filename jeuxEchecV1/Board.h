#pragma once
#include "PionGenerique.h"

class Board
{
public:
	Board();
	~Board();

	void initBoard();
	void displayBoard();

	void move();
	bool testMoveGeneral(int xDep, int yDep, int xArr, int yArr);
	int letterToNumber(char letter);

private:
	PionGenerique* board[8][8];
};

