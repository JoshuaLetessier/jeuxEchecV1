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
	int letterToNumber(char letter);

private:
	PionGenerique* board[8][8];
};

