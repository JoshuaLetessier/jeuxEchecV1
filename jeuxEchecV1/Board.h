#pragma once
#include "PionGenerique.h"

class Board
{
public:
	Board();
	~Board();

	void initBoard();

	PionGenerique* board[8][8];
};

